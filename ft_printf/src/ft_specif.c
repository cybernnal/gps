/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:26:08 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/25 22:56:36 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_pf_modulo(t_var *var)
{
	char	*tmp;

	if (var->width)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (2))))
			return (0);
		tmp[0] = '%';
		tmp[1] = '\0';
		tmp = ft_space(tmp, var);
		var->str = ft_free_join(var->str, tmp);
		return (1);
	}
	else if ((var->str = ft_free_join(var->str, "%")))
		return (1);
	return (0);
}

int			ft_pf_char(t_var *var)
{
	char		c;

	if (var->flag & FLAG_L)
	{
		ft_pf_wchar(var);
		return (1);
	}
	if (var->ind == 0)
		var->index = (int*)malloc(sizeof(int) * 100);
	var->free = 1;
	c = (char)va_arg(var->ap, int);
	if (c == '\0')
	{
		c = '*';
		if (!(var->flag & FLAG_NEG))
			var->index[var->ind] = ft_strlen(var->str) + var->width - 1;
		else
			var->index[var->ind] = ft_strlen(var->str);
		var->ind++;
	}
	var->str = ft_add_char(var->str, c, var);
	return (1);
}

int			ft_pf_string(t_var *var)
{
	char	*tmp;

	if (var->flag & FLAG_L)
	{
		ft_pf_wcstr(var);
		return (1);
	}
	tmp = NULL;
	if (!(tmp = (char*)va_arg(var->ap, void *)))
	{
		var->free1 = 1;
		tmp = ft_strdup("(null)");
	}
	else
		var->free = -1;
	if (var->flag & FLAG_PR)
		tmp = ft_preci_str(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_free_join(var->str, tmp);
	if (var->free1 == 1)
		ft_memdel((void **)&tmp);
	var->free1 = 0;
	return (1);
}
