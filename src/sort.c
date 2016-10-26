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

