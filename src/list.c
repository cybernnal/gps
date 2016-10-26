/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 14:23:45 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/23 15:30:10 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			addlst_p(t_pile **list, t_pile **first)
{
	if (!(*list))
	{
		if (!((*list) = (t_pile*)malloc(sizeof(t_pile))))
			return (0);
		(*list)->next = NULL;
		(*first) = (*list);
	}
	else
	{
		if (!((*list)->next = (t_pile*)malloc(sizeof(t_pile))))
			return (0);
		(*list) = (*list)->next;
		(*list)->next = NULL;
	}
	return (1);
}

int			build_lst(t_env *env, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = argc - 2;
	env->p1 = NULL;
	while (j >= 0)
	{
		if (!(addlst_p(&env->p1, &env->first1)))
			return (-1);
		env->p1->nb = env->tmp[i];
        i++;
		j--;
	}
	env->p1 = env->first1;
	return (1);
}
