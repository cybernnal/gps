/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:58:24 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/20 21:07:10 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			get_med(int nb, int rest)
{
	static t_pile	*p;
	static t_pile	*first;
	int				i;

	i = 1;
	if (rest == 1 || !p)
		return (med2(&p, &first, nb, rest));
	p = first;
	med3(&p, &first, nb);
	while (p->next && (i++))
		p = p->next;
	p = first;
	i++;
	i /= 2;
	while (p && i > 1)
	{
		p = p->next;
		i--;
	}
	return (p->nb);
}

int			is_sort(t_pile *p1, t_pile *first1)
{
	while (p1->next && p1->nb < p1->next->nb)
		p1 = p1->next;
	if (p1->next == NULL && (p1 = first1))
		return (0);
	p1 = first1;
	return (1);
}

int			is_rsort(t_pile *p1, t_pile *first1)
{
	while (p1->next && p1->nb > p1->next->nb)
		p1 = p1->next;
	if (p1->next == NULL && (p1 = first1))
		return (0);
	p1 = first1;
	return (1);
}

int			is_bsort(t_pile *p1, t_pile *first1)
{
	while (p1->next->next && p1->nb < p1->next->nb)
		p1 = p1->next;
	if (p1->next != NULL && p1->next->next == NULL && (p1 = first1))
		return (0);
	p1 = first1;
	return (1);
}

int			is_psort(t_pile *p1, t_pile *first1)
{
	int		i;
	int		j;

	i = 0;
	while (p1->next && (p1->nb > p1->next->nb || i <= 10))
	{
		if (p1->nb < p1->next->nb)
		{
			j = p1->next->nb;
			i++;
		}
		p1 = p1->next;
	}
	if (p1->next == NULL && (p1 = first1))
		return (j);
	p1 = first1;
	return (0);
}
