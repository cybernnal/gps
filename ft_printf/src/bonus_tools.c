/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 03:18:00 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/25 22:53:58 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_pf_bin(t_var *var)
{
	intmax_t	n;
	char		*tmp;

	n = ft_get_int(var);
	if (n < 0)
		n = -n;
	tmp = ft_getbit(n);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_free_join(var->str, tmp);
	ft_memdel((void **)&tmp);
	return (1);
}

char		*ft_getbit(uintmax_t n)
{
	unsigned int	t;
	int				i;
	int				j;
	char			*ret;
	int				k;

	ret = NULL;
	j = 0;
	i = 31;
	t = 1;
	k = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (33))))
		return (0);
	ft_bzero(ret, 33);
	while (i >= 0)
	{
		if (n & t << i)
			ret[k] = '1';
		else
			ret[k] = '0';
		i--;
		k++;
	}
	return (ret);
}
