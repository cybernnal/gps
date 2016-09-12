/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:46:30 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 17:09:49 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*norm_ld(char *tmp)
{
	ft_memdel((void **)&tmp);
	tmp = ft_strdup("0.000000");
	return (tmp);
}

char	*norm_exp(t_var *var, char *str, int j)
{
	char	*tmp;

	tmp = NULL;
	if (str[ft_strlen(str) - 1] == '0')
		str[ft_strlen(str) - 1] = '\0';
	if (str[ft_strlen(str) - 1] == '.')
		str[ft_strlen(str) - 1] = '\0';
	if (j < 10)
		str = ft_free2_join(str, ft_strjoin((var->form[var->i] ==
						'E' ? "E+0" : "e+0"), ft_itoa(j)));
	else
		str = ft_free2_join(str, ft_strjoin((var->form[var->i] ==
						'E' ? "E+" : "e+"), ft_itoa(j)));
	if (!(tmp = ft_strdup(str)))
		return (NULL);
	ft_memdel((void **)&str);
	return (tmp);
}

int		norm_gl(t_var *var, char **tmp)
{
	if (var->form[var->i] == 'G')
		var->form[var->i] = 'E';
	if ((var->flag & FLAG_PR) && !var->preci)
		var->preci = 1;
	else if (!(var->flag & FLAG_PR))
		var->preci = 6;
	*tmp = ft_ld(var);
	return (ft_strlen(*tmp));
}
