/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:21:46 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/25 22:50:11 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_zero(t_var *var, int x)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (2))))
		return (NULL);
	if (x == 0)
		tmp[0] = '0';
	else
		tmp[0] = '*';
	tmp[1] = '\0';
	if (x == 1)
	{
		var->index[var->ind] = ft_strlen(var->str) + var->width - 1;
		var->ind++;
	}
	return (tmp);
}

void		ft_tab_ft_init(int (**tab_ft)(t_var *))
{
	tab_ft['%'] = &ft_pf_modulo;
	tab_ft['c'] = &ft_pf_char;
	tab_ft['s'] = &ft_pf_string;
	tab_ft['i'] = &ft_pf_nb;
	tab_ft['d'] = &ft_pf_nb;
	tab_ft['u'] = &ft_pf_unb;
	tab_ft['o'] = &ft_pf_oct;
	tab_ft['x'] = &ft_pf_hex;
	tab_ft['X'] = &ft_pf_hexup;
	tab_ft['p'] = &ft_pf_mem;
	tab_ft['O'] = &ft_pf_l;
	tab_ft['D'] = &ft_pf_l;
	tab_ft['U'] = &ft_pf_l;
	tab_ft['C'] = &ft_pf_wchar;
	tab_ft['S'] = &ft_pf_wcstr;
	tab_ft['n'] = &ft_pf_intn;
	tab_ft['b'] = &ft_pf_ubin;
	tab_ft['B'] = &ft_pf_bin;
	tab_ft['f'] = &ft_pf_ld;
	tab_ft['F'] = &ft_pf_ld;
	tab_ft['e'] = &ft_pf_eld;
	tab_ft['E'] = &ft_pf_eld;
	tab_ft['g'] = &ft_pf_gld;
	tab_ft['G'] = &ft_pf_gld;
}

int			ft_check_flag(t_var *var)
{
	int		b;

	b = 1;
	if (var->form[var->i] == '#' && (var->flag |= FLAG_DI))
		return (1);
	else if (var->form[var->i] == '0' && (var->flag |= FLAG_ZE))
		return (1);
	else if (var->form[var->i] == '-' && (var->flag |= FLAG_NEG))
		return (1);
	else if (var->form[var->i] == '+' && (var->flag |= FLAG_POS))
		return (1);
	else if (var->form[var->i] == ' ' && (var->flag |= FLAG_SP))
		return (1);
	else
		return (0);
}

int			ft_check_modif(t_var *var)
{
	int		b;

	b = 1;
	if (var->form[var->i] == 'h' && var->form[var->i + 1] == 'h' &&
			(var->flag |= FLAG_HH) && (var->i += 1))
		return (1);
	else if (var->form[var->i] == 'l' && var->form[var->i + 1] == 'l' &&
			(var->flag |= FLAG_LL) && (var->i += 1))
		return (1);
	else if (var->form[var->i] == 'j' && (var->flag |= FLAG_J))
		return (1);
	else if (var->form[var->i] == 'L' && (var->flag |= FLAG_GL))
		return (1);
	else if (var->form[var->i] == 'h' && (var->flag |= FLAG_H))
		return (1);
	else if (var->form[var->i] == 'l' && (var->flag |= FLAG_L))
		return (1);
	else if (var->form[var->i] == 'z' && (var->flag |= FLAG_Z))
		return (1);
	else
		return (0);
}
