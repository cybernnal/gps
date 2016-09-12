/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:56:20 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/24 01:27:38 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_free_join(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (s1 && *s1)
		ft_memdel((void **)&s1);
	return (str);
}

char		*ft_add_char(char *str, char c, t_var *var)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	tmp[0] = c;
	tmp[1] = '\0';
	if (var->width)
		tmp = ft_space(tmp, var);
	if (str)
		str = ft_free_join(str, tmp);
	else
		return (tmp);
	ft_memdel((void **)&tmp);
	return (str);
}

char		*to_ubaseup(uintmax_t n, int b)
{
	char		*s;
	char		hex[128];
	uintmax_t	t;
	int			i;

	i = 0;
	if (!(s = malloc(sizeof(char) * 128)))
		return (NULL);
	ft_memset(s, 0, 128);
	ft_memset(hex, 0, 128);
	while (n)
	{
		t = n % b;
		if (t < 10)
			hex[i] = t + '0';
		else
			hex[i] = t + 'A' - 10;
		i++;
		n = n / b;
	}
	t = 0;
	while (i)
		s[t++] = hex[--i];
	return (s);
}

char		*to_ubase(uintmax_t n, int b)
{
	char		*s;
	char		hex[128];
	uintmax_t	t;
	int			i;

	i = 0;
	if (!(s = malloc(sizeof(char) * 128)))
		return (NULL);
	ft_memset(s, 0, 128);
	ft_memset(hex, 0, 128);
	while (n)
	{
		t = n % b;
		if (t < 10)
			hex[i] = t + '0';
		else
			hex[i] = t + 'a' - 10;
		i++;
		n = n / b;
	}
	t = 0;
	while (i)
		s[t++] = hex[--i];
	return (s);
}

char		*to_base(intmax_t n, int b)
{
	char		*s;
	char		hex[128];
	intmax_t	t;
	int			i;

	i = 0;
	if (!(s = malloc(sizeof(char) * 128)))
		return (NULL);
	ft_memset(s, 0, 128);
	ft_memset(hex, 0, 128);
	while (n)
	{
		t = n % b;
		if (t < 10)
			hex[i] = t + '0';
		else
			hex[i] = t + 'a' - 10;
		i++;
		n = n / b;
	}
	t = 0;
	while (i)
		s[t++] = hex[--i];
	return (s);
}
