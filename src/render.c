//
// Created by Raphaël Dantzer on 11/09/16.
//

#include <time.h>
#include "push_swap.h"

static void key_handler(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			exit(EXIT_SUCCESS);
        if (event.key.keysym.sym == SDLK_UP)
            get_env()->px++;
        if (event.key.keysym.sym == SDLK_DOWN)
            get_env()->px--;
        if (event.key.keysym.sym == SDLK_LEFT && get_env()->py > 1)
            get_env()->py--;
        if (event.key.keysym.sym == SDLK_RIGHT && get_env()->py < WIN_HEIGHT - 1)
            get_env()->py++;
    }
}

static void draw_pixel(int x, int y, Uint32 color, t_window *w)
{
	w->img_ptr[WIN_WIDTH * y + x] = color;
}

void drawcircle(int x0, int y0, int radius, Uint32 color, t_window *w)
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		draw_pixel(x0 + x, y0 + y, color, w);
		draw_pixel(x0 + y, y0 + x, color, w);
		draw_pixel(x0 - y, y0 + x, color, w);
		draw_pixel(x0 - x, y0 + y, color, w);
		draw_pixel(x0 - x, y0 - y, color, w);
		draw_pixel(x0 - y, y0 - x, color, w);
		draw_pixel(x0 + y, y0 - x, color, w);
		draw_pixel(x0 + x, y0 - y, color, w);
		++y;
		err += 1 + 2*y;
		if (2 * (err - x) + 1 > 0)
		{
			--x;
			err += 1 - 2*x;
		}
	}
}

# define LINEAR_CONVERSION(X, x1, x2, y1, y2) (((float)((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)


static void render_pile2( t_window *w, t_pile *p, int offset, int rad, int x0, int y0)
{
    t_pile *tmp = p;
    static int total = 0;
    int tt = offset;
    int px = get_env()->px;
    int py = get_env()->py;

    if (total == 0)
        total = get_env()->total_size;
    while (y0 + rad < WIN_HEIGHT )
    {
        while (tmp)
        {
            ++offset;
            tmp = tmp->next;
        }
        tmp = p;
        offset--;
        drawcircle(x0, y0, (int) LINEAR_CONVERSION(offset, 0, total, 0, rad), tmp->color /* * circ * y0*/, w);
        offset = tt;
        y0 += py;
        x0 -= px;
    }
}

static void render_pile22(t_window *w, t_pile *p, int offset)
{
    int rad;
    static int x = 0;
    static int y = 0;
    static int ex;
    static int ey;

    rad =  WIN_WIDTH / 2 / NB_CIRCLE;
    if (x == 0 && y == 0)
    {
        x =  WIN_WIDTH - rad;
        y = rad;
    }
    else if ((!(SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))  ||
                                    !(y + rad < WIN_HEIGHT && y > 0 && x > 0 && x + rad < WIN_WIDTH && y - rad > 0 && x - rad > 0)))
    {
        x =  ex;
        y = ey;
    }
    ex = x;
    ey = y;
    render_pile2(w, p, offset, rad, x, y);
}

static void render_pile( t_window *w, t_pile *p, int offset)
{
    t_pile *tmp = p;
    static int total = 0;
    int         height;
    int         y0;
    int         rad;
    int tt = offset;
    int circ = 1;

    if (total == 0)
        total = get_env()->total_size;
    rad = WIN_WIDTH / 2 / NB_CIRCLE;
    y0 = rad + rad;
    height = y0;
    while (y0 <= WIN_HEIGHT - height)
    {
        while (circ + 1 <= NB_CIRCLE)//* 2 )
        {
            while (tmp)
            {
                drawcircle((rad * circ*2), y0, (int) LINEAR_CONVERSION(offset, 0, total, 0, rad), tmp->color /* * circ * y0*/, w);
                ++offset;
                tmp = tmp->next;
            }
            ++circ;
            tmp = p;
            offset = tt;
        }
        circ = 1;
        y0 += height;
    }
    y0 = rad;
    while (y0 <= WIN_HEIGHT - rad)
    {
        while (circ <= NB_CIRCLE)// * 2)
        {
            while (tmp)
            {
                drawcircle((rad * circ*2)-rad, y0, (int) LINEAR_CONVERSION(offset, 0, total, 0, rad), tmp->color /* * circ * y0*/, w);
                ++offset;
                tmp = tmp->next;
            }
            ++circ;
            tmp = p;
            offset = tt;
        }
        circ = 1;
        y0 += rad * 2;
    }
}

void        render(t_pile *a, t_pile *b) {
	static t_window w;
	(void) b;

	if (!w.is_init)
	{
		init_window(&w);
		w.is_init = 1;
	}
    bzero(w.img_ptr, sizeof(Uint32) * WIN_HEIGHT * WIN_WIDTH);
    while (SDL_PollEvent(&w.event)) {
        key_handler(w.event);
    }
	render_pile22(&w, a, 0); // change to render_pile22   // use left clique mouse and up/down/left/right key for tricks
	SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIN_WIDTH * sizeof(Uint32));
	SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
	SDL_RenderPresent(w.renderer);
}
