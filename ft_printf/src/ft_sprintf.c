/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:19:59 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/25 23:31:24 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_sprintf(char *str, const char *restrict format, ...)
{
	t_var	var;
	int		i;
	int		j;

	j = 0;
	intvar(&var);
	va_start(var.ap, format);
	if (!(var.form = ft_strdup(format)))
		return (-1);
	ft_pars_string(&var);
	i = ft_strlen(var.str);
	if (var.naze == -1)
	{
		ft_memdel((void **)&var.form);
		ft_memdel((void **)&var.str);
		return (-1);
	}
	norm(&var, 9999999, str);
	ft_memdel((void **)&var.str);
	intvar(&var);
	return (i);
}
