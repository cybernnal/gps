/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:26:08 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 16:43:08 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_pf_mem(t_var *var)
{
	uintmax_t	n;
	char		*tmp;

	n = (uintmax_t)va_arg(var->ap, void *);
	if (n == 0 && !(var->flag & FLAG_PR))
		tmp = ft_zero(var, 0);
	else
		tmp = to_ubase(n, 16);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (!(var->flag & FLAG_ZE) && (var->ptr = tmp))
	{
		tmp = ft_strjoin("0x", tmp);
		ft_memdel((void **)&var->ptr);
	}
	else
		var->width -= 2;
	if (var->width)
		tmp = ft_space(tmp, var);
	if ((var->flag & FLAG_ZE))
		tmp = ft_strjoin("0x", tmp);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}

char		*wctost(wchar_t wc, t_var *var)
{
	char tmp[5];

	if (norm_wch(var, wc, tmp) == 1)
		return (ft_strdup("NULL"));
	if (wc <= 0x7F && (var->pwc += 1))
		tmp[0] = (char)wc;
	else if (wc <= 0x7FF && (var->pwc += 2))
	{
		tmp[0] = (((wc >> 6) | 0xC0) & 0xDF);
		tmp[1] = ((wc | 0x80) & 0xBF);
	}
	else if (wc <= 0xFFFF && (var->pwc += 3))
	{
		tmp[0] = (((wc >> 12) | 0xE0) & 0xEF);
		tmp[1] = ((wc >> 6) | 0x80) & 0xBF;
		tmp[2] = ((wc | 0x80) & 0xBF);
	}
	else if (wc <= 0x10FFFF && (var->pwc += 4))
	{
		tmp[0] = (((wc >> 18) | 0xF0) & 0xF7);
		tmp[1] = (((wc >> 12) | 0x80) & 0xBF);
		tmp[2] = (((wc >> 6) | 0x80) & 0xBF);
		tmp[3] = ((wc | 0x80) & 0xBF);
	}
	return (ft_strdup(tmp));
}

int			ft_pf_wchar(t_var *var)
{
	wchar_t wc;
	char	*tmp;
	char	*ptr;

	if (var->ind == 0)
		var->index = (int*)malloc(sizeof(int) * 100);
	var->free = 1;
	if (!(wc = (wchar_t)va_arg(var->ap, void *)))
	{
		if (!(tmp = ft_zero(var, 1)))
			return (0);
	}
	else
		tmp = wctost(wc, var);
	if ((var->pwc = 0) && var->width)
	{
		ptr = tmp;
		tmp = ft_space(ptr, var);
		ft_memdel((void **)&ptr);
	}
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}

int			ft_pf_wcstr(t_var *var)
{
	char		*tmp;
	wchar_t		*wc;

	tmp = NULL;
	wc = NULL;
	if (!(wc = (wchar_t*)va_arg(var->ap, void *)))
	{
		var->free = 1;
		tmp = ft_free_join(tmp, "(null)");
	}
	else if ((var->free = -1))
		tmp = norm_wcst(var, wc, tmp);
	var->pwc = 0;
	if (var->flag & FLAG_PR)
		tmp = ft_preci_str(tmp, var);
	if (var->flag & FLAG_PR && var->preci == 0)
		tmp = NULL;
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}
