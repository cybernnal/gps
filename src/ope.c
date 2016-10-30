/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:55:33 by tbillard          #+#    #+#             */
/*   Updated: 2016/09/13 00:24:49 by rdantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 ** sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a.
 ** pa : push a - prend le premier élément au sommet de b et le met sur a.
 ** pb : push b - prend le premier élément au sommet de a et le met sur b.
 ** ra : rotate a - décale d’une position tous les élements de la pile a.
 ** rra : reverse rotate a
 */

int		sa(t_env *env)
{
	int tmp;

	tmp = env->p1->nb;
	env->p1->nb = env->p1->next->nb;
	env->p1->next->nb = tmp;
	tmp = env->p1->qs;
	env->p1->qs = env->p1->next->qs;
	env->p1->next->qs = tmp;
	ft_print_op(env, 5, "sa");
	if (env->flag & 2)
		ft_printlst_p(env->p1);
	env->op++;
	process_list(get_env()->p1);
	process_list(get_env()->p2);
	render(get_env()->p1, get_env()->p2);
	return (1);
}

int		pa(t_env *env)
{
	env->first2 = env->p2->next;
	env->p2->next = env->p1;
	env->first1 = env->p2;
	env->p1 = env->first1;
	env->p2 = env->first2;
	ft_print_op(env, 4, "pa");
	if (env->flag & 2)
		ft_printlst_p(env->p1);
	env->op++;
	render(get_env()->p1, get_env()->p2);
	return (1);
}

int		pb(t_env *env)
{
	env->first1 = env->p1->next;
	env->p1->next = env->p2;
	env->first2 = env->p1;
	env->p1 = env->first1;
	env->p2 = env->first2;
	ft_print_op(env, 3, "pb");
	if (env->flag & 2)
		ft_printlst_p(env->p1);
	env->op++;
	render(get_env()->p1, get_env()->p2);
	return (1);
}

int		ra(t_env *env)
{
	t_pile	*tmp;

	env->first1 = env->first1->next;
	tmp = get_last(env->p1, 0);
	tmp->next = env->p1;
	env->p1->next = NULL;
	env->p1 = env->first1;
	ft_print_op(env, 6, "ra");
	if (env->flag & 2)
		ft_printlst_p(env->p1);
	env->op++;
	render(get_env()->p1, get_env()->p2);
	return (1);
}

int		rra(t_env *env)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = get_last(env->p1, 0);
	tmp2 = get_last(env->p1, 1);
	tmp2->next = NULL;
	tmp->next = env->first1;
	env->first1 = tmp;
	env->p1 = env->first1;
	ft_print_op(env, 7, "rra");
	if (env->flag & 2)
		ft_printlst_p(env->p1);
	env->op++;
	render(get_env()->p1, get_env()->p2);
	return (1);
}
