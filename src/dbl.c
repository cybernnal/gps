/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:18:36 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/20 18:51:06 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_error(void)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}

int		is_nb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		dbl2(char **argv, t_env *env)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!is_nb(argv[i]))
			return (-1);
		env->tmp[i - 1] = ft_atoi(argv[i]);
		if (env->tmp[i - 1] >= 2147483647 || env->tmp[i - 1] <= -2147483647 ||
				ft_strlen(argv[i]) > 10)
			return (-1);
		if (-env->min > env->tmp[i - 1] && env->tmp[i - 1] < 0)
			env->min = -env->tmp[i - 1];
		if (env->max < env->tmp[i - 1] && env->tmp[i - 1] > 0)
			env->max = env->tmp[i - 1];
		i++;
	}
	return (i);
}

int		dbl3(t_env *env, int i, char *pos, char *neg)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (env->tmp[j] >= 0)
			if (pos[env->tmp[j]] == 1)
				return (-1);
			else
				pos[env->tmp[j]] = 1;
		else
		{
			if (neg[(-(env->tmp[j]))] == 1)
				return (-1);
			else
				neg[(-(env->tmp[j]))] = 1;
		}
		j++;
	}
	return (1);
}

int		dblon(int argc, char **argv, t_env *env)
{
	int		i;
	int		j;
	char	*pos;
	char	*neg;

	i = 1;
	j = 0;
	env->min = 0;
	env->max = 0;
	if (!(env->tmp = (int*)malloc(sizeof(int) * (argc + 1))))
		return (-1);
	if ((i = dbl2(argv, env)) == -1)
		return (-1);
	if (!(pos = ft_strnew(env->max + 1)) ||
			!(neg = ft_strnew(env->min + 1)))
		return (-1);
	i--;
	if (dbl3(env, i, pos, neg) == -1)
		return (-1);
	free(pos);
	free(neg);
	return (1);
}
