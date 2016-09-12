/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litle_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 22:36:28 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/19 18:43:54 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		go_top(t_env *env)
{
	int *j;

	j = get_nb(env->p1, env->first1);
	while (env->p1->nb != j[0])
	{
		if (j[1] == 0)
			ra(env);
		else
			rra(env);
	}
}

int			ft_median(t_env *env)
{
	int		i;

	while (env->p1)
	{
		i = get_med(env->p1->nb, 0);
		env->p1 = env->p1->next;
	}
	env->p1 = env->first1;
	ra(env);
	while (env->p1->nb != i && env->p1->qs == 0)
	{
		if (env->p1->nb > i && env->p1->qs == 0)
			pb(env);
		else
			ra(env);
	}
	env->p1->qs = 1;
	ra(env);
	while (env->p2)
		pa(env);
	return (i);
}

int			ft_midmedian(t_env *env)
{
	int		i;

	i = env->min;
	while (env->p1->nb != i)
	{
		if (env->p1->nb > i && env->p1->qs == 0)
			pb(env);
		else
			ra(env);
	}
	env->p1->qs = 1;
	ra(env);
	while (env->p2)
		pa(env);
	return (i);
}

void		ft_median2(t_env *env, t_pile *ftmp, int i)
{
	while (env->p1->qs == 0)
	{
		if (env->p1->nb < i)
			break ;
		env->p1 = env->p1->next;
	}
	if (env->p1->qs != 1 && (env->p1 = env->first1))
		while (env->p1->qs == 0)
		{
			if (env->p1->nb < i && env->p1->qs == 0)
				pb(env);
			else
				ra(env);
		}
	env->p1 = env->first1;
	while (env->p1->nb != ftmp->nb)
	{
		if (find_nb(env->p1, ftmp->nb))
			rra(env);
		else
			ra(env);
	}
	ra(env);
	while (env->p2)
		pa(env);
}

void		push_min(t_env *env)
{
	int		*j;
	int		k;

	k = 0;
	j = get_nb(env->p1, env->first1);
	while (env->p1->nb != j[0])
	{
		if (j[1] == 0)
			ra(env);
		else
			rra(env);
		k++;
	}
	pb(env);
	while (k > 0)
	{
		if (j[1] == 0)
			rra(env);
		else
			ra(env);
		k--;
	}
	pa(env);
	env->p1->qs = 1;
}
