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
        // y = node->size;
        // if ((node->next && node->next->size > node->size) || !node->next)
        // {
            drawcircle(WIN_WIDTH - WIN_HEIGHT / 2, WIN_HEIGHT / 2, LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT / 2), node->color, w);
        // }
        // draw_pixel(x, y + 1, (255 << 16) + (255 << 8) + 255, w);
    }
    else
    {
        y = WIN_HEIGHT - node->size + 1;
        // if ((node->next && node->next->size > node->size) || !node->next)
        // {
                drawcircle(WIN_HEIGHT / 2, WIN_HEIGHT / 2, LINEAR_CONVERSION(x, 0, get_env()->total_size, 0, WIN_HEIGHT / 2), node->color, w);
        // }
        // draw_pixel(x, y - 1 , (255 << 16) + (255 << 8) + 255, w);
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
    // get_env()->a_size = get_list_size(a);
    // get_env()->b_size = get_list_size(b);
    render_pile(&w, a, 0);
    render_pile(&w, b, 1);
    SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIN_WIDTH * sizeof(Uint32));
    SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
    SDL_RenderPresent(w.renderer);
}
