/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 00:14:04 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/20 18:13:56 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			is_med_sort2(t_env *env)
{
	while (env->p1->qs == 0)
	{
		if (env->p1->nb < env->min)
		{
			env->p1 = env->first1;
			return (0);
		}
		env->p1 = env->p1->next;
	}
	env->p1 = env->first1;
	return (1);
}

void		opt3(t_env *env, int *argc, char ***argv)
{
	if (ft_strcmp((*argv)[1], "-o") == 0)
	{
		env->flag |= 8;
		(*argv)++;
		(*argc)--;
	}
	if (ft_strcmp((*argv)[1], "-l") == 0)
	{
		env->flag |= 16;
		(*argv)++;
		(*argc)--;
	}
	if (ft_strcmp((*argv)[1], "-v") == 0)
	{
		env->flag |= 2;
		(*argv)++;
		(*argc)--;
	}
	if (ft_strcmp((*argv)[1], "-p") == 0)
	{
		env->flag |= 4;
		(*argv)++;
		(*argc)--;
	}
}

void		opt2(t_env *env, int *argc, char ***argv)
{
	if (ft_strcmp((*argv)[1], "-c") == 0)
	{
		env->flag |= 1;
		(*argv)++;
		(*argc)--;
	}
	if ((ft_strcmp((*argv)[1], "-m") == 0))
	{
		(*argv)++;
		(*argc)--;
		env->flag |= 128;
	}
	if ((ft_strcmp((*argv)[1], "-qs") == 0))
	{
		(*argv)++;
		(*argc)--;
		env->flag |= 64;
	}
	if ((ft_strcmp((*argv)[1], "-bs") == 0))
	{
		(*argv)++;
		(*argc)--;
		env->flag |= 32;
	}
}

int			med2(t_pile **p, t_pile **first, int nb, int rest)
{
	if (rest == 1)
	{
		free_lst(p);
		return (0);
	}
	if (!(*p))
	{
		(*p) = (t_pile*)malloc(sizeof(t_pile));
		(*first) = (*p);
		(*p)->nb = nb;
		(*p)->next = NULL;
		return (nb);
	}
	return (0);
}

void		med3(t_pile **p, t_pile **first, int nb)
{
	t_pile *tmp;

	if (nb < (*p)->nb)
	{
		(*p) = (t_pile*)malloc(sizeof(t_pile));
		(*p)->next = (*first);
		(*first) = (*p);
		(*p)->nb = nb;
	}
	else
	{
		while ((*p)->next && (*p)->next->nb < nb)
			(*p) = (*p)->next;
		tmp = (*p)->next;
		(*p)->next = (t_pile*)malloc(sizeof(t_pile));
		(*p)->next->nb = nb;
		(*p)->next->next = tmp;
	}
	(*p) = (*first);
}
