/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupnfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:28:26 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/24 00:02:48 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupnfree(char *s1)
{
	int			i;
	int			j;
	char		*s2;

	i = 0;
	j = 0;
	s2 = NULL;
	while (s1[i])
		i++;
	if ((s2 = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	while (s1[j])
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	ft_memdel((void **)&s1);
	return (s2);
}
