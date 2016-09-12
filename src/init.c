//
// Created by Raphaël Dantzer on 11/09/16.
//

#include "push_swap.h"

# define LINEAR_CONVERSION(X, x1, x2, y1, y2) (((float)((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)

void process_list(t_pile *p)
{ 
	const int   max = WIN_HEIGHT / 2;
	const int   min = 0;
	t_pile      *tmp;

	tmp = p;
	while (tmp)
	{ 
		tmp->size = LINEAR_CONVERSION(tmp->nb, get_env()->smallest, get_env()->biggest, min, max);
		tmp = tmp->next;
	}
}

static void init_texture_renderer(t_window *win, int w, int h)
{
	if (!(win->img_ptr = (Uint32 *)ft_memalloc(sizeof(Uint32) * w * h)))
		exit(EXIT_FAILURE);
	win->image = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
}

void        init_window(t_window *window)
{
	SDL_Init(SDL_INIT_VIDEO);
	if (!(window->window = SDL_CreateWindow("push_swap", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN)))
		exit(EXIT_FAILURE);
	if (!(window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED)))
		exit(EXIT_FAILURE);
	init_texture_renderer(window, WIN_WIDTH, WIN_HEIGHT);
	window->step_x = WIN_WIDTH / get_env()->total_size;
	window->step_y = WIN_HEIGHT / 4;
}
