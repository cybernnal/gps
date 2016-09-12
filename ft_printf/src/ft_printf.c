/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:19:59 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/24 18:02:35 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_put_end(t_var *var)
{
	int		i;
	int		j;

	i = 0;
	j = var->ind - 1;
	while (var->ind > 0)
	{
		if (var->str[var->index[i]] == '*')
			var->str[var->index[i]] = '\0';
		else if (var->str[var->index[i] + 1] == '*')
			var->str[var->index[i] + 1] = '\0';
		var->ind--;
		i++;
	}
}

void	intvar(t_var *var)
{
	var->neg = 0;
	var->ind = 0;
	var->width = 0;
	var->preci = 0;
	var->flag = 0;
	var->arg = 0;
	var->ret = 0;
	var->i = 0;
	var->free = 0;
	var->free1 = 0;
	var->index = 0;
	var->pwc = 0;
	var->spe = 0;
	var->naze = 0;
	var->str = NULL;
	var->tmp = NULL;
	var->form = NULL;
	var->ptr = NULL;
}

int		ft_printf(const char *restrict format, ...)
{
	t_var	var;
	int		i;

	intvar(&var);
	va_start(var.ap, format);
	if (!(var.form = ft_strdup(format)))
		return (-1);
	ft_pars_string(&var);
	va_end(var.ap);
	i = ft_strlen(var.str);
	if (var.ind != 0)
		ft_put_end(&var);
	if (var.free == 1)
		ft_memdel((void **)&var.index);
	if (var.naze == -1)
	{
		ft_memdel((void **)&var.form);
		ft_memdel((void **)&var.str);
		return (-1);
	}
	write(1, var.str, i);
	ft_memdel((void **)&var.form);
	ft_memdel((void **)&var.str);
	intvar(&var);
	return (i);
}
