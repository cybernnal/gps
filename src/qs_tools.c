/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:10:21 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/19 18:04:45 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		qs_whle(t_env *env, t_pile *ftmp, int k, int i)
{
	while (is_sort(env->p1, env->first1) || env->p2)
	{
		if (sa_d(env))
			return ;
		while (env->p1->qs == 1)
			env->p1 = env->p1->next;
		k = env->p1->nb;
		env->p1 = env->first1;
		while (env->p1->nb != k && (ftmp = env->first1))
		{
			if (find_nb(env->p1, k))
				rra(env);
			else
				ra(env);
		}
		if (!is_med_sort(env))
		{
			i = ft_midmedian(env);
			ft_median2(env, ftmp, i);
		}
		if (!is_round_sort(env->p1))
			break ;
	}
}

void		rab(t_pile **p, t_pile **f)
{
	t_pile *tmp;

	(*f) = (*f)->next;
	tmp = get_last(*p, 0);
	tmp->next = (*p);
	(*p)->next = NULL;
	(*p) = (*f);
}

int			is_round_sort(t_pile *p)
{
	t_pile	*f;
	int		*j;

	f = p;
	j = get_nb(p, f);
	while (p->next)
	{
		if (p->nb > p->next->nb && p->next->nb != j[0])
			return (1);
		p = p->next;
	}
	p = f;
	return (0);
}

int			find_nb(t_pile *p, int j)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (p)
	{
		if (p->nb == j)
			k = i;
		i++;
		p = p->next;
	}
	if (k > i / 2)
		return (1);
	return (0);
}

void		qs_opt(t_env *env)
{
	if (env->p1->qs == 1)
	{
		ra(env);
		if (env->p1->qs == 0 && env->p1->next->qs == 1)
		{
			env->p1->next->qs = 1;
			ra(env);
			ra(env);
		}
	}
}
