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

int			addlst_start(t_pile **list, t_pile **first)
{
	t_pile *tmp;

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
			return (-1);
		tmp = (*list)->next;
		(*list)->next = NULL;
		tmp->next = (*first);
		(*first) = tmp;
	}
	return (1);
}

int			sig_flag(t_env *env, int i)
{
	static unsigned int	flag;

	if (i == 1)
		flag = env->flag;
	return (flag);
}

void		ft_printlst_p(t_pile *list)
{
	if (list)
	{
		ft_putendl("");
		while (list)
		{
			ft_putnbr(list->nb);
			if ((sig_flag(NULL, 0)) & 4)
			{
				ft_putstr("  qs: ");
				ft_putnbr(list->qs);
			}
			ft_putendl("");
			list = list->next;
		}
	}
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
		env->p1->qs = 0;
		i++;
		j--;
	}
	env->p1 = env->first1;
	return (1);
}
