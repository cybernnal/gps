/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 23:32:57 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 16:46:15 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	norm_gld(t_var *var, char **tmp, char **ptr, int *i)
{
	if (var->form[var->i] == 'G')
		var->form[var->i] = 'E';
	if ((var->flag & FLAG_PR) && !var->preci)
		var->preci = 1;
	else if (!(var->flag & FLAG_PR))
		var->preci = 6;
	*tmp = ft_ld(var);
	*ptr = ft_strsub(*tmp, 0, var->preci);
	*i = ft_strlen(*tmp);
	while (*tmp[*i - 1] == '0')
	{
		(*i)--;
		*tmp[*i] = '\0';
	}
}

void	norm_sp(t_var *var)
{
	if (var->flag & FLAG_SP)
		var->width--;
	if ((var->flag & FLAG_DI) && (var->flag & FLAG_ZE) && var->spe == 'x')
		var->width -= 2;
	else if (((var->flag & FLAG_ZE) && (var->flag & FLAG_POS)) ||
			((var->flag & FLAG_ZE) && var->neg == 1))
		var->width--;
}

int		norm_wch(t_var *var, wchar_t wc, char *tmp)
{
	ft_bzero(tmp, 5);
	if ((wc < 0 || (wc > 55295 && wc < 57344) || wc > 1114111)
						&& (var->naze = -1))
		return (1);
	return (0);
}

char	*norm_wcst(t_var *var, wchar_t *wc, char *tmp)
{
	char	*ptr;

	while (*wc)
	{
		ptr = wctost(*wc, var);
		if ((var->preci) && (var->pwc > var->preci + 1))
		{
			ft_memdel((void**)&ptr);
			break ;
		}
		tmp = ft_free12_join(tmp, ptr);
		if (*wc++)
			;
	}
	return (tmp);
}
