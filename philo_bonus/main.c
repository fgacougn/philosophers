/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:01:21 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 16:41:04 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	end(t_env *env)
{
	sem_destroy(&(env->mutex));
	sem_destroy(&(env->start));
	sem_destroy(&(env->end));
	sem_destroy(&(env->ankou));
	sem_destroy(&(env->forks));
	sem_destroy(&(env->cptmeals));
	if (env->philos)
		free(env->philos);
	if (env->party)
		free(env->party);
	return (0);
}

static int	start(t_env *env)
{
	if (sem_init(&(env->mutex), 0, 1))
		return (end(env));
	if (sem_init(&(env->start), 0, 1))
		return (end(env));
	if (sem_init(&(env->end), 0, 1))
		return (end(env));
	sem_wait(&(env->start));
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	static t_env	env;

	if (argc < 5 || argc > 6 || ft_parse(argc, argv, &env) != SUCCESS)
		return (0);
	if (start(&env) == 0)
		return (0);
	if (env.pop > 1)
	{
		if (ft_init_meal(&env) != SUCCESS)
			end(&env);
		ft_start_meal(&env);
	}
	else
	{
		if (env.pop == 1)
		{
			printf("0 1 has taken a fork\n");
			usleep(1000 * env.die);
			printf("%d 1 died\n", env.die);
		}
		sem_post(&(env.start));
	}
	end(&env);
	return (0);
}
