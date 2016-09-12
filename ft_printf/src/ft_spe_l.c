/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spe_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 13:27:05 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/20 13:47:44 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_pf_l(t_var *var)
{
	var->flag |= FLAG_L;
	ft_ver_flag(var);
	if (var->form[var->i] == 'O')
		ft_pf_oct(var);
	else if (var->form[var->i] == 'U')
		ft_pf_unb(var);
	else if (var->form[var->i] == 'D')
		ft_pf_nb(var);
	return (1);
}
