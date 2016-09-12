/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 17:55:39 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 16:28:28 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_ver_flag(t_var *var)
{
	if ((var->form[var->i] == 'c' || var->form[var->i] == 's') &&
			(var->flag & FLAG_DI))
		var->flag ^= FLAG_DI;
	if ((var->flag & FLAG_POS) && (var->flag & FLAG_SP))
		var->flag ^= FLAG_SP;
	if ((var->flag & FLAG_ZE) && (var->flag & FLAG_NEG))
		var->flag ^= FLAG_ZE;
	if ((var->flag & FLAG_HH) && (var->flag & FLAG_H))
		var->flag ^= FLAG_HH;
	if ((var->flag & FLAG_LL) && (var->flag & FLAG_L))
		var->flag ^= FLAG_L;
	if (((var->flag & FLAG_H) && (var->flag & FLAG_LL)) ||
			((var->flag & FLAG_H) && (var->flag & FLAG_L)))
		var->flag ^= FLAG_H;
	if (((var->flag & FLAG_HH) && (var->flag & FLAG_LL)) ||
			((var->flag & FLAG_HH) && (var->flag & FLAG_L)))
		var->flag ^= FLAG_HH;
	if (var->flag & FLAG_J || var->flag & FLAG_Z)
		ft_ver_flag2(var);
	if ((var->flag & FLAG_PR) && var->flag & FLAG_ZE && !cc(var, 'c') &&
			!cc(var, 's') && !cc(var, 'S') && !cc(var, 'C') && !cc(var, '%'))
		var->flag ^= FLAG_ZE;
	return (1);
}

void		ft_ver_flag2(t_var *var)
{
	if (var->flag & FLAG_J && var->flag & FLAG_Z)
		var->flag ^= FLAG_Z;
	if ((var->flag & FLAG_J || var->flag & FLAG_Z) && var->flag & FLAG_L)
		var->flag ^= FLAG_L;
	if ((var->flag & FLAG_J || var->flag & FLAG_Z) && var->flag & FLAG_LL)
		var->flag ^= FLAG_LL;
	if ((var->flag & FLAG_J || var->flag & FLAG_Z) && var->flag & FLAG_H)
		var->flag ^= FLAG_H;
	if ((var->flag & FLAG_J || var->flag & FLAG_Z) && var->flag & FLAG_HH)
		var->flag ^= FLAG_HH;
}

char		*ft_preci_nb(char *str, t_var *var)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!var->preci && (var->flag & FLAG_PR) && str[0] == '0')
		return (NULL);
	if (ft_strlen(str) >= (size_t)var->preci)
		return (str);
	if (!(tmp = (char*)malloc(sizeof(char) *
					(ft_strlen(str) + var->preci + 1))))
		return (0);
	ft_bzero(tmp, (ft_strlen(str) + var->preci + 1));
	j = var->preci - ft_strlen(str);
	ft_memset(tmp, '0', j);
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	ft_memdel((void **)&str);
	return (tmp);
}

char		*ft_preci_str(char *str, t_var *var)
{
	char	*tmp;
	int		i;
	int		j;

	j = ft_strlen(str) - ((ft_strlen(str) - var->preci));
	i = 0;
	if (ft_strlen(str) <= (size_t)var->preci)
		return (str);
	if (!(tmp = (char*)malloc(sizeof(char) * (j + 1))))
		return (0);
	ft_bzero(tmp, j + 1);
	while (j > 0)
	{
		tmp[i] = str[i];
		i++;
		j--;
	}
	return (tmp);
}

char		*ft_space(char *str, t_var *var)
{
	char	*tmp;

	tmp = NULL;
	var->width -= ft_strlen(str);
	norm_sp(var);
	if (var->width <= 0 && var->spe != 'c')
		return (str);
	if (!(tmp = (char*)malloc(sizeof(char) * (var->width + 1))))
		return (0);
	ft_memset(tmp, '\0', var->width + 1);
	if (var->flag & FLAG_ZE)
		ft_memset(tmp, '0', var->width);
	else
		ft_memset(tmp, ' ', var->width);
	if (var->flag & FLAG_NEG && var->free != -1)
		str = ft_free_join(str, tmp);
	else if (var->flag & FLAG_NEG && var->free == -1)
		str = ft_strjoin(str, tmp);
	else if (var->free >= 0)
		str = ft_free2_join(tmp, str);
	else
		str = ft_strjoin(tmp, str);
	ft_memdel((void **)&tmp);
	return (str);
}
