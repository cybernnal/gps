/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 20:21:53 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 19:35:11 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_pf_ubin(t_var *var)
{
	uintmax_t	n;
	char		*tmp;

	n = ft_get_uint(var);
	tmp = ft_getbit(n);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}

int				ft_pf_intn(t_var *var)
{
	int		*i;

	i = (int*)va_arg(var->ap, void *);
	*i = ft_strlen(var->str);
	return (1);
}

static void		putcol(t_var *var, char *color)
{
	var->str = ft_free_join(var->str, color);
}

void			ft_end_color(t_var *var)
{
	if (var->flag & FLAG_COLOR)
		var->str = ft_free_join(var->str, CL_0);
	var->flag = 0;
}

int				ft_color(t_var *var)
{
	if (var->form[var->i + 1] == '{' && var->form[var->i + 2] == '(')
	{
		var->flag |= FLAG_COLOR;
		var->i += 3;
		if (var->form[var->i] == '0')
			putcol(var, CL_0);
		else if (var->form[var->i] == '1')
			putcol(var, CL_1);
		else if (var->form[var->i] == '2')
			putcol(var, CL_2);
		else if (var->form[var->i] == '3')
			putcol(var, CL_3);
		else if (var->form[var->i] == '4')
			putcol(var, CL_4);
		else if (var->form[var->i] == '5')
			putcol(var, CL_5);
		else if (var->form[var->i] == '6')
			putcol(var, CL_6);
		else if (var->form[var->i] == '7')
			putcol(var, CL_7);
		else if (var->form[var->i] == '8')
			putcol(var, CL_8);
		var->i += 2;
	}
	return (1);
}
