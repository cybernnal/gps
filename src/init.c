//
// Created by Raphaël Dantzer on 11/09/16.
//

#include "push_swap.h"

static Uint32   get_rainbow_color(int i)
{
    int r, g, b;
    const float frequency = 0.05f;

    r = (int)(sinf(frequency * i + 0) * 127 + 128);
    g = (int)(sinf(frequency * i + 2) * 127 + 128);
    b = (int)(sinf(frequency * i + 4) * 127 + 128);
    return ((Uint32 )((r << 16) + (g << 8) + b));
}

# define LINEAR_CONVERSION(X, x1, x2, y1, y2) (((float)((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)

void process_list(t_pile *p)
{ 
	const int   max = WIN_HEIGHT / 2;
	const int   min = 0;
	t_pile      *tmp;

	tmp = p;
	while (tmp)
	{ 
		tmp->size = (int)LINEAR_CONVERSION(tmp->nb, get_env()->smallest, get_env()->biggest, min, max);
		tmp->color = get_rainbow_color(tmp->size);
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
	if (!(window->window = SDL_CreateWindow("psyc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN)))
		exit(EXIT_FAILURE);
	if (!(window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED)))
		exit(EXIT_FAILURE);
	init_texture_renderer(window, WIN_WIDTH, WIN_HEIGHT);
	//SDL_SetWindowFullscreen(window->window, SDL_WINDOW_FULLSCREEN);// TODO full screen but refract code for W / H
}
