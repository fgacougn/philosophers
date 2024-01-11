/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:20:08 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 16:38:36 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// int	ft_parse(int argc, char **argv, t_env *env)
// {
// 	static int	i;

// 	env->pop = ft_atoi(argv[1]);
// 	env->die = ft_atoi(argv[2]);
// 	env->eat = ft_atoi(argv[3]);
// 	env->sleep = ft_atoi(argv[4]);
// 	if (env->pop < 0)
// 	{
// 		write(2, "No antiphilosopher yet\n", 23);
// 		return (ERR_BAD_READ);
// 	}
// 	if (env->die < 0 || env->eat < 0 || env->sleep < 0)
// 	{
// 		write(2, "No time travel yet\n", 19);
// 		return (ERR_BAD_READ);
// 	}
// 	if (argc == 6)
// 	{
// 		env->meals = ft_atoi(argv[5]);
// 		if (env->meals < 0)
// 			env->meals = 0;
// 		env->try = &ft_restaurant;
// 		if (sem_init(&(env->closing), 0, 1))
// 			return (ERR_SEMAPHORE);
// 	}
// 	else
// 	{
// 		env->meals = -1;
// 		env->try = &ft_philotry;
// 	}
// 	gettimeofday(&(env->start_time), NULL);
// 	printf("%ld %ld\n", env->start_time.tv_sec, env->start_time.tv_usec);
// 	gettimeofday(&(env->current_time), NULL);
// 	env->party = malloc(env->pop * sizeof(t_philo));
// 	if (!env->party)
// 		return (ERR_MALLOC);
// 	if (sem_init(&(env->ankou), 0, 1))
// 		return (ERR_SEMAPHORE);
// 	if (sem_init(&(env->forks), 0, env->pop))
// 		return (ERR_SEMAPHORE);
// 	if (sem_init(&(env->cptmeals), 0, env->pop))
// 		return (ERR_SEMAPHORE);
// 	i = 0;
// 	while (i < env->pop)
// 	{
// 		env->party[i].meal = &(env->cptmeals);
// 		env->party[i].forks = &(env->forks);
// 		env->party[i].env = env;
// 		env->party[i].number = i + 1;
// 		env->party[i].sleep = env->sleep;
// 		env->party[i].die = env->die;
// 		env->party[i].eat = env->eat;
// 		env->party[i].meals = 0;
// 		env->party[i].smeals = env->meals;
// 		env->party[i].start = &(env->start);
// 		env->party[i].pop = env->pop;
// 		env->party[i].ankou = &(env->ankou);
// 		env->party[i].start_time = &(env->start_time);
// 		env->party[i].parcae = &(env->parcae);
// 		env->party[i].snip = &(env->snip);
// 		env->party[i].try = env->try;
// 		env->party[i].last_call = &(env->lastcall);
// 		env->party[i].closing = &(env->closing);
// 		if (env->party[i].meals != -1)
// 			env->party[i].hasmeals = 1;
// 		else
// 			env->party[i].hasmeals = 0;
// 		env->party[i].micro = &(env->mutex);
// 		i++;
// 	}
// 	return (SUCCESS);
// }

static int	philovalid(t_env *env, int argc, char **argv)
{
	if (env->pop < 0)
	{
		write(2, "No antiphilosopher yet\n", 23);
		return (ERR_BAD_READ);
	}
	if (env->die < 0 || env->eat < 0 || env->sleep < 0)
	{
		write(2, "No time travel yet\n", 19);
		return (ERR_BAD_READ);
	}
	if (argc == 6)
	{
		env->meals = ft_atoi(argv[5]);
		if (env->meals < 0)
			env->meals = 0;
		env->try = &ft_restaurant;
		if (sem_init(&(env->closing), 0, 1))
			return (ERR_SEMAPHORE);
	}
	else
	{
		env->meals = -1;
		env->try = &ft_philotry;
	}
	return (SUCCESS);
}

static int	philomallocmutex(t_env *env)
{
	gettimeofday(&(env->start_time), NULL);
	gettimeofday(&(env->current_time), NULL);
	env->party = malloc(env->pop * sizeof(t_philo));
	if (!env->party)
		return (ERR_MALLOC);
	if (sem_init(&(env->ankou), 0, 1))
		return (ERR_SEMAPHORE);
	if (sem_init(&(env->forks), 0, env->pop))
		return (ERR_SEMAPHORE);
	if (sem_init(&(env->cptmeals), 0, env->pop))
		return (ERR_SEMAPHORE);
	return (SUCCESS);
}

static void	philoset(t_env *env, int i)
{
	env->party[i].meal = &(env->cptmeals);
	env->party[i].forks = &(env->forks);
	env->party[i].env = env;
	env->party[i].number = i + 1;
	env->party[i].sleep = env->sleep;
	env->party[i].die = env->die;
	env->party[i].eat = env->eat;
	env->party[i].meals = 0;
	env->party[i].smeals = env->meals;
	env->party[i].start = &(env->start);
	env->party[i].pop = env->pop;
	env->party[i].ankou = &(env->ankou);
	env->party[i].start_time = &(env->start_time);
	env->party[i].parcae = &(env->parcae);
	env->party[i].snip = &(env->snip);
	env->party[i].try = env->try;
	env->party[i].last_call = &(env->lastcall);
	env->party[i].closing = &(env->closing);
	if (env->party[i].meals != -1)
		env->party[i].hasmeals = 1;
	else
		env->party[i].hasmeals = 0;
	env->party[i].micro = &(env->mutex);
}

int	ft_parse(int argc, char **argv, t_env *env)
{
	static int	i;

	env->pop = ft_atoi(argv[1]);
	env->die = ft_atoi(argv[2]);
	env->eat = ft_atoi(argv[3]);
	env->sleep = ft_atoi(argv[4]);
	if (philovalid(env, argc, argv) != SUCCESS)
		return (ERR_BAD_READ);
	gettimeofday(&(env->start_time), NULL);
	gettimeofday(&(env->current_time), NULL);
	i = philomallocmutex(env);
	if (i != SUCCESS)
		return (i);
	i = 0;
	while (i < env->pop)
	{
		philoset(env, i);
		i++;
	}
	return (SUCCESS);
}
