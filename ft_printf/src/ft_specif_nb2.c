/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:26:20 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/24 00:00:38 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_pf_unb(t_var *var)
{
	uintmax_t	n;
	char		*tmp;

	n = ft_get_uint(var);
	if (n == 0 && !(var->flag & FLAG_PR))
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (2))))
			return (0);
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	else
		tmp = to_ubase(n, 10);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}
