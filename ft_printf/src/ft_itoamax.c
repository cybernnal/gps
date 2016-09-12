/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoamax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:06:16 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/18 20:14:06 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_itoamax(intmax_t n)
{
	char			*str;
	intmax_t		save;
	intmax_t		neg;
	intmax_t		i;

	save = n;
	neg = (n < 0 ? -1 : 1);
	i = 1 + (n < 0);
	while (n /= 10)
		i++;
	if (!(str = ft_strnew(i)))
		return (0);
	str[i--] = '\0';
	str[i--] = neg * (save % 10) + 48;
	while (save /= 10)
		str[i--] = neg * (save % 10) + 48;
	if (neg < 0)
		str[i] = '-';
	return (str);
}
