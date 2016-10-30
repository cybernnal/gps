/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 18:42:17 by tbillard          #+#    #+#             */
/*   Updated: 2016/09/15 15:56:46 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/include/ft_printf.h"
#include "SDL.h"
#define WIN_WIDTH   2000
#define WIN_HEIGHT  1000

typedef struct			s_window
{ 
	SDL_Window      	*window;
	SDL_Event       	event;
	SDL_Renderer    	*renderer;
	SDL_Texture     	*image;
	Uint32          	*img_ptr;
	int             	is_init;
}                   		t_window;


typedef struct			s_pile
{
	int			nb;
	int			qs;
	Uint32          	color;
	int	        	size;
	struct s_pile		*next;
}				t_pile;

typedef struct			s_env
{
	int			min;
	int			max;
	int             	biggest;
	int             	smallest;
	int             	total_size;
	int			op;
	unsigned int		flag;
	int			*tmp;
	char			*neg;
	t_pile			*p1;
	t_pile			*first1;
	t_pile			*p2;
	t_pile			*first2;
}				t_env;

t_env				*get_env();
void				render( t_pile *a, t_pile *b);
void				init_window( t_window *window);
void				process_list( t_pile *p);
void				sort_round(t_env *env);
void				sort_quick(t_env *env);
void				algo(t_env *env, int argc);
int				sig_flag(t_env *env, int i);
void				ft_print_op(t_env *env, int c, char *op);
void				go_top(t_env *env);
int				ft_median(t_env *env);
int				ft_midmedian(t_env *env);
void				ft_median2(t_env *env, t_pile *ftmp, int i);
void				qs_whle(t_env *env, t_pile *ftmp, int k, int i);
void				push_min(t_env *env);
int				sa_d(t_env *env);
int				find_nb(t_pile *p, int j);
int				addlst_p(t_pile **list, t_pile **first);
void				ft_printlst_p(t_pile *list);
int				build_lst(t_env *env, int argc);
int				ft_error(void);
void				free_lst(t_pile **p);
int				dblon(int argc, char **argv, t_env *env);
t_pile				*get_last(t_pile *p1, int n);
int				*get_nb(t_pile *p, t_pile *first);
void				exept(t_env *env, int argc);
int				get_med(int nb, int rest);
int				is_round_sort(t_pile *p);
int				is_sort(t_pile *p1, t_pile *first1);
int				is_rsort(t_pile *p1, t_pile *first1);
int				is_bsort(t_pile *p1, t_pile *first1);
int				is_psort(t_pile *p1, t_pile *first1);
int				is_med_sort(t_env *env);
int				is_med_sort2(t_env *env);
void				opt2(t_env *env, int *argc, char ***argv);
void				opt3(t_env *env, int *argc, char ***argv);
int				med2(t_pile **p, t_pile **first, int nb, int rest);
void				med3(t_pile **p, t_pile **first, int nb);
int				sa(t_env *env);
int				pa(t_env *env);
int				pb(t_env *env);
int				ra(t_env *env);
int				rra(t_env *env);

#endif
