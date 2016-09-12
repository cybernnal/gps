/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 23:07:28 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/25 23:10:09 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	norm(t_var *var, size_t size, char *str)
{
	int		j;

	j = 0;
	if (var->ind != 0)
		ft_put_end(var);
	if (var->free == 1)
		ft_memdel((void **)&var->index);
	va_end(var->ap);
	size--;
	while (var->str[j] && size > 0)
	{
		str[j] = var->str[j];
		size--;
		j++;
	}
	str[j] = '\0';
	ft_memdel((void **)&var->form);
}

int		ft_snprintf(char *str, size_t size, const char *restrict format, ...)
{
	t_var	var;
	int		i;

	intvar(&var);
	va_start(var.ap, format);
	if (!(var.form = ft_strdup(format)))
		return (-1);
	ft_pars_string(&var);
	i = ft_strlen(var.str);
	norm(&var, size, str);
	if (var.naze == -1)
	{
		ft_memdel((void **)&var.form);
		ft_memdel((void **)&var.str);
		return (-1);
	}
	ft_memdel((void **)&var.str);
	intvar(&var);
	return (i);
}
