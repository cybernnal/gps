/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldtoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 16:17:36 by tbillard          #+#    #+#             */
/*   Updated: 2016/04/26 16:40:48 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_in(t_ld *env, long double ld, int preci)
{
	if (preci == -1)
		env->preci = 6;
	else
		env->preci = preci;
	env->save = ld;
	env->nb = ld;
	env->nbdiv = 0;
	env->nbmult = 0;
}

static void		ft_toatoa(t_ld *env, long double ld)
{
	int		nbdv;

	if ((1 / ld) < 0 && (ld = -ld))
	{
		env->ret[env->i++] = '-';
		env->neg = 1;
		env->nb = ld;
	}
	while (env->nb >= 1 && (env->nbdiv += 1))
		env->nb /= 10;
	nbdv = env->nbdiv;
	while (env->nb > 0 && env->i < env->preci + 1 + nbdv + env->neg)
	{
		env->nbmult++;
		if ((env->nbmult > env->nbdiv) && (env->nbdiv = 42424242))
		{
			if (!env->i || env->ret[env->i - 1] == '-')
				env->ret[env->i++] = '0';
			env->ret[env->i++] = '.';
		}
		env->nb *= 10;
		env->ret[env->i++] = ((int)env->nb) + '0';
		env->nb -= (int)env->nb;
	}
	env->ret[env->i] = '\0';
}

static void		ft_round_off(t_ld *env)
{
	if (((int)(env->nb * 10)) < 5)
		return ;
	env->i = (int)ft_strlen(env->ret);
	while (env->ret[--env->i])
	{
		if (env->ret[env->i] == '.')
			continue ;
		else if (env->ret[env->i] == '9')
			env->ret[env->i] = '0';
		else
			break ;
	}
	if (env->ret[env->i] != '-')
		env->ret[env->i] = ((env->ret[env->i] - '0') + 1) + '0';
}

static int		exept(t_ld *env, t_var *var, long double ld)
{
	char c;

	c = var->form[var->i];
	if (ld == 1.0 / 0.0)
	{
		if (c == 'F' || c == 'E' || c == 'G')
			env->ret = ft_strdup("INF");
		else
			env->ret = ft_strdup("inf");
	}
	else if (ld == -1.0 / 0.0)
	{
		if (c == 'F' || c == 'E' || c == 'G')
			env->ret = ft_strdup("-INF");
		else
			env->ret = ft_strdup("-inf");
	}
	else if (ld == 0.0 / 0.0)
		env->ret = ft_strdup("nan");
	else
		return (1);
	return (0);
}

char			*ldtoa(t_var *var, long double ld, int preci)
{
	t_ld	env;
	char	*ztr;

	ztr = NULL;
	env.i = 0;
	env.neg = 0;
	if (!(exept(&env, var, ld)))
		return (env.ret);
	if (!(env.ret = ft_strnew(1024)))
		return (NULL);
	ft_in(&env, ld, preci);
	ft_toatoa(&env, ld);
	if ((env.ret[0] == '1' && ft_strlen(env.ret) == 1) ||
			(env.ret[0] == '-' && env.ret[1] == '1' && ft_strlen(env.ret) == 2))
	{
		if (!(ztr = (char*)malloc(sizeof(char) * (env.nbdiv + 7))))
			return (NULL);
		ft_memset(ztr, '\0', env.nbdiv + 7);
		ft_memset(ztr, '0', env.nbdiv + 6);
		ztr[env.nbdiv - 1] = '.';
		env.ret = ft_free12_join(env.ret, ztr);
	}
	ft_round_off(&env);
	return (env.ret);
}
