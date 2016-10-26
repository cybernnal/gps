/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:46:15 by tbillard          #+#    #+#             */
/*   Updated: 2016/10/25 12:27:39 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init(t_env *env)
{
	env->p1 = NULL;
	env->p2 = NULL;
	env->first1 = NULL;
    env->flag = 0;
    env->py = 5;
    env->px = 10;
}

t_env    *get_env()
{ 
	static t_env    *env;

	if (!env)
		env = (t_env *)ft_memalloc(sizeof(t_env));
	return env;
}

int		main(int argc, char **argv)
{
	t_env		*env;

	env = get_env(); 
	init(env);
	if (argc == 1)
		return (0);
	if (dblon(argc, argv, env) == -1 || build_lst(env, argc) == -1)
		return (ft_error());
    env->biggest = env->max;
	env->smallest = -env->min;
	env->total_size = argc - 1;
	process_list(get_env()->p1);
    int i = 0;
    while (1)
        ra(env);
	return (0);
}
