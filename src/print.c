/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:34:48 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/20 17:45:09 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_op2(t_env *env, int c, char *op)
{
	if (env->flag & 1)
	{
		if (c == 5)
			ft_printf(" %{(5)}s", op);
		if (c == 4)
			ft_printf(" %{(4)}s", op);
		if (c == 3)
			ft_printf(" %{(3)}s", op);
		if (c == 6)
			ft_printf(" %{(6)}s", op);
		if (c == 7)
			ft_printf(" %{(7)}s", op);
		return ;
	}
	ft_putstr(" ");
	ft_putstr(op);
}

void	ft_print_op(t_env *env, int c, char *op)
{
	if (env->flag & 128)
		return ;
	if (env->op == 0)
	{
		if (env->flag & 1)
		{
			if (c == 5)
				ft_printf("%{(5)}s", op);
			if (c == 4)
				ft_printf("%{(4)}s", op);
			if (c == 3)
				ft_printf("%{(3)}s", op);
			if (c == 6)
				ft_printf("%{(6)}s", op);
			if (c == 7)
				ft_printf("%{(7)}s", op);
		}
		else
			ft_putstr(op);
		return ;
	}
	ft_print_op2(env, c, op);
}
