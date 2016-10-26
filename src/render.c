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

static void render_pile( t_window *w, t_pile *p, int offset)
{
    t_pile *tmp = p;
    static int total = 0;
    int         width;
    int         height;
    int         x0;
    int         y0;
    int         rad;
    int tt = offset;
    int circ = 0;
    int is = 0;
    int mod;

    rad = WIN_WIDTH / NB_CIRCLE / 2;
    y0 = WIN_HEIGHT / 2;
    if (rad * 2 <= WIN_HEIGHT / 2)
    {
  //      rad = WIN_WIDTH / 4;
        y0 = WIN_HEIGHT / 4;
        is = 1;
    }
    x0 = WIN_WIDTH / (NB_CIRCLE + 1);
    if (total == 0)
        total = get_env()->total_size;
    mod = rad * 2 / WIN_HEIGHT;
    while (mod)
    {
        while (circ < NB_CIRCLE)
        {
            while (tmp)
            {
                width = 2 * RADIUS_MAX * NB_CIRCLE;
                drawcircle((rad * circ * 2) - rad, y0, (int) LINEAR_CONVERSION(offset, 0, total, 0, rad), tmp->color,
                           w);
                ++offset;
                tmp = tmp->next;
            }
            // if (is == 1 && circ == NB_CIRCLE / 2)
            //   y0 = WIN_HEIGHT - y0;
            ++circ;
            tmp = p;
            offset = tt;
        }
        mod --;
        y0 = WIN_HEIGHT - y0;
    }
    /*
    tmp = p;
    offset = tt;
    while (tmp)
    {
        width = 2 * RADIUS_MAX * NB_CIRCLE;
        drawcircle(rad * 2, WIN_HEIGHT / 2, (int)LINEAR_CONVERSION(offset, 0, total, 0, radWIN_HEIGHT / 2), tmp->color, w);
        ++offset;
        tmp = tmp->next;
    }
    tmp = p;
    offset = tt;
    while (tmp)
    {
        width = 2 * RADIUS_MAX * NB_CIRCLE;
        drawcircle(rad * 3, WIN_HEIGHT / 2, (int)LINEAR_CONVERSION(offset, 0, total, 0, radWIN_HEIGHT / 2), tmp->color, w);
        ++offset;
        tmp = tmp->next;
    }
*/
}

void        render(t_pile *a, t_pile *b) {
	static t_window w;
	(void) b;

	if (!w.is_init)
	{
		init_window(&w);
		w.is_init = 1;
	}
	while (SDL_PollEvent(&w.event)) {
        key_handler(w.event);
    }
	render_pile(&w, a, 0);
	SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIN_WIDTH * sizeof(Uint32));
	SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
	SDL_RenderPresent(w.renderer);
}
