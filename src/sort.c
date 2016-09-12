/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:40:47 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/20 17:55:18 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*get_last(t_pile *pl, int n)
{
	t_pile	*tmp;

	tmp = pl->next;
	if (n == 1)
	{
		while (pl && pl->next && tmp->next)
		{
			pl = pl->next;
			tmp = tmp->next;
		}
	}
	else
		while (pl && pl->next)
			pl = pl->next;
	if (!pl)
		return (NULL);
	return (pl);
}

int		*get_nb(t_pile *p, t_pile *first)
{
	int		*ret;
	int		i;
	int		k;

	if (!(ret = (int*)malloc(sizeof(int) * (2))))
		return (0);
	i = 0;
	ret[0] = 2147483647;
	k = 0;
	while (p)
	{
		if (p->nb <= ret[0])
		{
			k = i;
			ret[0] = p->nb;
		}
		p = p->next;
		i++;
	}
	if (k > i / 2)
		ret[1] = 1;
	else
		ret[1] = 0;
	p = first;
	return (ret);
}

void	sort_round(t_env *env)
{
	int		*i;

	if (!is_sort(env->p1, env->first1))
		return ;
	while (env->p1->next->next)
	{
		if ((i = get_nb(env->p1, env->first1)) && i[1] == 0)
		{
			while (env->p1->nb != i[0])
				ra(env);
			pb(env);
		}
		else
		{
			while (env->p1->nb != i[0])
				rra(env);
			pb(env);
		}
	}
	if (env->p1->nb > env->p1->next->nb)
		sa(env);
	while (env->p2)
		pa(env);
}

void	sort_quick(t_env *env)
{
	int		i;
	int		k;
	t_pile	*ftmp;

	k = 0;
	push_min(env);
	ftmp = env->first1;
	i = ft_median(env);
	ft_median2(env, ftmp, i);
	if (!is_sort(env->p1, env->first1))
		return ;
	rra(env);
	qs_whle(env, ftmp, k, i);
	go_top(env);
}
