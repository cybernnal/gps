/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:02:27 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 00:10:34 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_free2_join(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (s2 && *s2)
		ft_memdel((void **)&s2);
	return (str);
}

char		*ft_free12_join(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (s2 && *s2)
		ft_memdel((void **)&s2);
	if (s1 && *s1)
		ft_memdel((void **)&s1);
	return (str);
}

int			cc(t_var *var, char c)
{
	if (var->form[var->i] == c)
		return (1);
	return (0);
}
