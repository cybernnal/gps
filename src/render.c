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

		y += 1;
		err += 1 + 2*y;
		if (2*(err-x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2*x;
		}
	}
}

static Uint32   get_rainbow_color( int i)
{ 
	int r, g, b;
	const float frequency = 0.01f;
	const int	n = WIN_HEIGHT / ( i + 0.0001f);

	r = ( int)( sinf( frequency * i + 0) * 127 + 128);
	g = ( int)( sinf( frequency * i + 2) * 127 + 128);
	b = ( int)( sinf( frequency * i + 4) * 127 + 128);
	return ( ( Uint32 )( ( r << 16) + ( g << 8) + b));
}

static void drawsquare(int x0, int y0, t_pile *pile, t_window *w, int offset)
{
	int x = -offset/2;
	int y;

	while (x <= offset/2)
	{
		y = offset/2;
		while (y >= -offset/2)
		{
			draw_pixel(x + x0, y + y0, pile->color, w);
			if (x != -offset/2 && x != offset/2 && y != -offset/2)
				y = -offset/2;
			else
				y--;
		}
		x++;
	}
}

static void drawpyra(int x0, int y0, t_pile *pile, t_window *w, int offset)
{
	int x = -offset/2;
	int y;

	while (x <= offset/2)
	{
		y = offset/2;
		while (y >= -offset/2)
		{
			if (y > 0)
				draw_pixel(x + x0, y + y0, pile->color, w);
			if (x != -offset/2 || x != offset/2 || y != -offset/2)
				break ;
			else
				y--;
		}
		x++;
	}
}

static void drawpyra2b(int x0, int y0, t_pile *pile, t_window *w, int offset)
{
	int x = -offset/2;
	int y;

	while (x <= offset/2)
	{
		y = -offset/2;
				draw_pixel(x + x0, y + y0, pile->color, w);
		x++;
	}
}

static void drawpyra2(int x0, int y0, t_pile *pile, t_window *w, int offset)
{
	int x = -offset/2;
	int y;

	while (x <= offset/2)
	{
		y = offset/2;
				draw_pixel(x + x0, y + y0, pile->color, w);
		x++;
	}
}

# define LINEAR_CONVERSION(X, x1, x2, y1, y2) (((float)((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)

static void draw_rectangle(t_window *w, t_pile *node, int offset, int pile)
{
	int     x;
	int     y;
	Uint32  color;

	color = node->color;
	x = offset;
	if (pile)
	{
		if (get_env()->flag & 256)
			drawsquare(WIN_WIDTH - WIN_HEIGHT / 2, WIN_HEIGHT / 2, node, w,LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT / 2));
		else if (get_env()->flag & 512)
			drawpyra(WIN_WIDTH - WIN_HEIGHT / 2, WIN_HEIGHT / 2, node, w,LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT / 2));
		else if (get_env()->flag & 1024)
			drawpyra2b(WIN_WIDTH / 2, WIN_HEIGHT / 2, node, w,LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT - 10));
		else
			drawcircle(WIN_WIDTH - WIN_HEIGHT / 2, WIN_HEIGHT / 2, LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT / 2), node->color, w);
	}
	else
	{
		y = WIN_HEIGHT - node->size + 1;
		if (get_env()->flag & 256)
			drawsquare(WIN_HEIGHT / 2, WIN_HEIGHT / 2, node, w, LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT / 2));
		else if (get_env()->flag & 512)
			drawpyra(WIN_HEIGHT / 2, WIN_HEIGHT / 2, node, w, LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT / 2));
		else if (get_env()->flag & 1024)
			drawpyra2(WIN_WIDTH / 2, WIN_HEIGHT / 2, node, w,LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT - 10));
		else
		    drawcircle(WIN_HEIGHT / 2, WIN_HEIGHT / 2, LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT / 2), node->color, w);
	}
}

static void render_pile(t_window *w, t_pile *p, int pile)
{
    int             offset;
    t_pile *tmp = p;
    offset = -1;
    if (!tmp)
        return ;
    while (tmp)
    {
        draw_rectangle(w, tmp, offset++ + (get_env()->total_size < 800 ? 1 : 0), pile);
        tmp = tmp->next;
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
	while (SDL_PollEvent(&w.event))
		key_handler(w.event);
	render_pile(&w, a, 0);
	render_pile(&w, b, 1);
	SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIN_WIDTH * sizeof(Uint32));
	SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
	SDL_RenderPresent(w.renderer);
}
