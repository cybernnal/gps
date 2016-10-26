/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:55:33 by tbillard          #+#    #+#             */
/*   Updated: 2016/10/26 16:24:25 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ra(t_env *env)
{
	t_pile	*tmp;

	env->first1 = env->first1->next;
	tmp = get_last(env->p1, 0);
	tmp->next = env->p1;
	env->p1->next = NULL;
	env->p1 = env->first1;
    render(get_env()->p1, get_env()->p2);
	return (1);
}

