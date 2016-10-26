/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 18:42:17 by tbillard          #+#    #+#             */
/*   Updated: 2016/10/25 06:21:17 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "SDL2/SDL.h"
#define WIN_WIDTH   1270
#define WIN_HEIGHT  635
//#define RADIUS_MAX  250
#define NB_CIRCLE 4 // nombre pair

typedef struct      s_window
{ 
	SDL_Window      *window;
	SDL_Event       event;
	SDL_Renderer    *renderer;
	SDL_Texture     *image;
	Uint32          *img_ptr;
	int             is_init;
}                   t_window;


typedef struct		s_pile
{
	int				nb;
    Uint32          color;
	int		        size;
	struct s_pile	*next;
}					t_pile;

typedef struct		s_env
{
    int             px;
    int             py;
	int				min;
	int				max;
    int             biggest;
	int             smallest;
	int             total_size;
    unsigned int	flag;
	int				*tmp;
	char			*neg;
	t_pile			*p1;
	t_pile			*first1;
	t_pile			*p2;
}					t_env;

t_env				*get_env();
void				render( t_pile *a, t_pile *b);
void				init_window( t_window *window);
void				process_list( t_pile *p);
int					addlst_p(t_pile **list, t_pile **first);
int					build_lst(t_env *env, int argc);
int					ft_error(void);
int					dblon(int argc, char **argv, t_env *env);
t_pile				*get_last(t_pile *p1, int n);
int					ra(t_env *env);
int		rra(t_env *env);

#endif
