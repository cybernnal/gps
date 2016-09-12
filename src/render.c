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

static int  get_list_size(t_pile *p)
{
    t_pile  *tmp;
    int     size;

    size = 0;
    tmp = p;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return (size);
}

static Uint32   get_rainbow_color(int i)
{
    int r, g, b;
    const float frequency = 0.05f;

    r = (int)(sinf(frequency * i + 0) * 127 + 128);
    g = (int)(sinf(frequency * i + 2) * 127 + 128);
    b = (int)(sinf(frequency * i + 4) * 127 + 128);
    return ((Uint32 )((r << 16) + (g << 8) + b));
}

static void draw_pixel(int x, int y, Uint32 color, t_window *w)
{
    w->img_ptr[WIN_WIDTH * y + x] = color;
}

static void draw_rectangle(t_window *w, t_pile *node, int offset, int pile)
{
    int     x;
    int     y;

    x = offset;
    if (pile)
    {
        y = node->size;
        while (y--)
            draw_pixel(x, y, get_rainbow_color(node->nb), w);
    }
    else
    {
        y = WIN_HEIGHT - node->size;
        while (y++ < WIN_HEIGHT)
            draw_pixel(x, y, get_rainbow_color(node->nb), w);
    }
}

static void render_pile(t_window *w, t_pile *p, int count, int pile)
{
    int             offset;

    t_pile *tmp = p;
    offset = -1;
    if (!tmp)
        return ;
    while (++offset < count)
    {
        draw_rectangle(w, tmp, offset + (get_env()->total_size < 800 ? 1 : 0), pile);
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
    ft_bzero(w.img_ptr, sizeof(Uint32) * WIN_HEIGHT * WIN_WIDTH);
    while (SDL_PollEvent(&w.event))
        key_handler(w.event);
    get_env()->a_size = get_list_size(a);
    get_env()->b_size = get_list_size(b);
    render_pile(&w, a, get_env()->a_size, 0);
    render_pile(&w, b, get_env()->b_size, 1);
    SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIN_WIDTH * sizeof(Uint32));
    SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
    SDL_RenderPresent(w.renderer);
}
