/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:26:20 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 00:14:27 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_pf_nb(t_var *var)
{
	intmax_t	n;
	char		*tmp;

	n = ft_get_int(var);
	if (n < 0 && (var->neg = 1))
		n = -n;
	if ((tmp = ft_itoamax(n)) && var->flag & FLAG_PR)
		tmp = ft_preci_nb(tmp, var);
	if (var->neg == 1 && !(var->flag & FLAG_ZE) && (n + 1 != MAX))
		tmp = ft_free2_join("-", tmp);
	if (var->flag & FLAG_POS && n >= 0 && var->neg == 0 &&
			!(var->flag & FLAG_ZE))
		tmp = ft_free2_join("+", tmp);
	if (var->width)
		tmp = ft_space(tmp, var);
	if (var->flag & FLAG_POS && var->neg == 0 && (var->flag & FLAG_ZE))
		tmp = ft_free2_join("+", tmp);
	if (var->neg == 1 && (var->flag & FLAG_ZE) && (n + 1 != MAX))
		tmp = ft_free2_join("-", tmp);
	if (var->flag & FLAG_SP && n >= 0 && var->neg == 0)
		tmp = ft_free2_join(" ", tmp);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	var->neg = 0;
	return (1);
}

int		ft_pf_oct(t_var *var)
{
	uintmax_t	n;
	char		*tmp;

	var->spe = 'o';
	n = ft_get_uint(var);
	if (n == 0 && ((!(var->preci) && !(var->flag & FLAG_PR)) ||
				(var->flag & FLAG_DI)))
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (2))))
			return (0);
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	else
		tmp = to_ubase(n, 8);
	if ((var->flag & FLAG_DI) && n != 0)
		tmp = ft_strjoin("0", tmp);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}

int		ft_pf_hex(t_var *var)
{
	uintmax_t	n;
	char		*tmp;

	tmp = NULL;
	n = ft_get_uint(var);
	if (n == 0 && !(var->flag & FLAG_PR))
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (2))))
			return (0);
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	else
		tmp = to_ubase(n, 16);
	if ((var->spe = 'x') && var->preci)
		tmp = ft_preci_nb(tmp, var);
	if ((var->flag & FLAG_DI) && !(var->flag & FLAG_ZE) && n != 0)
		tmp = ft_free2_join("0x", tmp);
	if (var->width > 0)
		tmp = ft_space(tmp, var);
	if ((var->flag & FLAG_DI) && (var->flag & FLAG_ZE) && (n != 0))
		tmp = ft_free2_join("0x", tmp);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}

int		ft_pf_hexup(t_var *var)
{
	uintmax_t	n;
	char		*tmp;

	var->spe = 'x';
	n = ft_get_uint(var);
	if (n == 0 && !(var->flag & FLAG_PR))
		tmp = ft_zero(var, 0);
	else
		tmp = to_ubaseup(n, 16);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if ((var->flag & FLAG_DI) && !(var->flag & FLAG_ZE) && n != 0)
		tmp = ft_free2_join("0X", tmp);
	if (var->width)
		tmp = ft_space(tmp, var);
	if ((var->flag & FLAG_DI) && (var->flag & FLAG_ZE) && (n != 0))
		tmp = ft_free2_join("0X", tmp);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}
