/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 23:30:37 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/20 00:21:10 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			is_med_sort(t_env *env)
{
	get_med(0, 1);
	while (env->p1->qs == 0)
	{
		env->min = get_med(env->p1->nb, 0);
		env->p1 = env->p1->next;
	}
	env->p1 = env->first1;
	while (env->p1->nb != env->min)
	{
		if (env->p1->nb > env->min)
		{
			env->p1 = env->first1;
			return (0);
		}
		env->p1 = env->p1->next;
	}
	env->p1->qs = 1;
	env->p1 = env->p1->next;
	if (!is_med_sort2(env))
		return (0);
	return (1);
}

int			sa_d(t_env *env)
{
	if (!is_bsort(env->p1, env->first1) && is_sort(env->p1, env->first1))
	{
		rra(env);
		rra(env);
		sa(env);
		ra(env);
		sa(env);
		ra(env);
		ra(env);
		return (1);
	}
	return (0);
}

void		exept(t_env *env, int argc)
{
	if (!is_rsort(env->p1, env->first1) && argc == 4)
	{
		sa(env);
		rra(env);
	}
	if (env->p1->nb > env->p1->next->nb)
		sa(env);
	if (!is_bsort(env->p1, env->first1) && is_sort(env->p1, env->first1))
	{
		rra(env);
		rra(env);
		sa(env);
		ra(env);
		ra(env);
	}
}
