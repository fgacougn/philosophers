/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:01:21 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 15:06:28 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	freeingmutex(int size, pthread_mutex_t **mutexes)
{
	int	i;

	if (!size || !mutexes || !*mutexes)
		return ;
	i = 0;
	if (*mutexes)
	{
		while (i < size)
			pthread_mutex_destroy(&((*mutexes)[i++]));
		free(*mutexes);
		i = 0;
	}
}

int	end(t_env *env)
{
	pthread_mutex_destroy(&(env->mutex));
	pthread_mutex_destroy(&(env->start));
	pthread_mutex_destroy(&(env->end));
	pthread_mutex_destroy(&(env->ankou));
	freeingmutex(env->cptforks, &(env->forks));
	freeingmutex(env->ccptmeals, &(env->cptmeals));
	freeingmutex(env->cptends, &(env->ends));
	if (env->philos)
		free(env->philos);
	if (env->party)
		free(env->party);
	return (0);
}

static int	start(t_env *env)
{
	if (pthread_mutex_init(&(env->mutex), 0))
		return (end(env));
	if (pthread_mutex_init(&(env->start), 0))
		return (end(env));
	if (pthread_mutex_init(&(env->end), 0))
		return (end(env));
	pthread_mutex_lock(&(env->start));
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	static t_env	env;

	if (argc < 5 || argc > 6 || ft_parse(argc, argv, &env) != SUCCESS)
		return (end(&env));
	if (start(&env) == 0)
		return (0);
	if (env.pop > 1)
	{
		if (ft_init_meal(&env) != SUCCESS)
			return (end(&env));
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
		pthread_mutex_unlock(&(env.start));
	}
	return (end(&env));
}
