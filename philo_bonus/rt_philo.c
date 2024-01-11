/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:59:18 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 15:57:00 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// void	*rt_philo(void *param)
// {
// 	t_philo	*philo;
// 	int		start;
// 	int		(*try)(t_philo *, void (*f)(t_philo *, char *, int), char *, int);

// 	philo = param;
// 	try = philo->try;
// 	sem_wait(philo->meal);
// 	sem_wait(philo->start);
// 	sem_post(philo->start);
// 	sem_wait(philo->micro);
// 	sem_post(philo->micro);
// 	gettimeofday(&(philo->current_time), 0);
// 	gettimeofday(&(philo->last_meal), 0);
// 	start = 1;
// 	while (1)
// 	{
// 		if (philo->number % 2 && philo->number != philo->pop)
// 		{
// 			if (ft_philofork(philo, 0) == FAIL)
// 				break ;
// 		}
// 		else if (start && philo->number % 2 == 0)
// 		{
// 			if (ft_philofork(philo, 1600) == FAIL)
// 				break ;
// 		}
// 		else if (ft_philofork(philo, 1641) == FAIL)
// 			break ;
// 		if (try(philo, &ft_philosay, "is eating", 0) == DEATH)
// 		{
// 			sem_post(philo->forks);
// 			sem_post(philo->forks);
// 			break ;
// 		}
// 		ft_memcpy(&(philo->last_meal), &(philo->current_time),
// 			sizeof(struct timeval));
// 		philo->meals++;
// 		if (philo->smeals >= 0 && philo->meals == philo->smeals)
// 			sem_post(philo->meal);
// 		if ((philo->meals == 1 && philo->smeals == 0))
// 		{
// 			sem_post(philo->meal);
// 			philo->meals++;
// 		}
// 		usleep(1000 * philo->eat);
// 		sem_post(philo->forks);
// 		sem_post(philo->forks);
// 		if (try(philo, &ft_philosay, "is sleeping", philo->sleep) == DEATH)
// 			break ;
// 		usleep(1000 * philo->sleep);
// 		if (try(philo, &ft_philosay, "is thinking", 0) == DEATH)
// 			break ;
// 	}
// 	if (philo->smeals < 0 || philo->meals < philo->smeals || (philo->meals <= 1
// 			&& philo->smeals == 0))
// 		sem_post(philo->meal);
// 	return (0);
// }

static int	philoeat(t_philo *philo, int (*try)(struct s_philo *,
			void (*f)(struct s_philo *, char *, int), char *, int))
{
	if (try(philo, &ft_philosay, "is eating", 0) == DEATH)
	{
		sem_post(philo->forks);
		sem_post(philo->forks);
		return (DEATH);
	}
	ft_memcpy(&(philo->last_meal), &(philo->current_time),
		sizeof(struct timeval));
	philo->meals++;
	if (philo->smeals >= 0 && philo->meals == philo->smeals)
		sem_post(philo->meal);
	if ((philo->meals == 1 && philo->smeals == 0))
	{
		sem_post(philo->meal);
		philo->meals++;
	}
	usleep(1000 * philo->eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (try(philo, &ft_philosay, "is sleeping", philo->sleep) == DEATH)
		return (DEATH);
	usleep(1000 * philo->sleep);
	if (try(philo, &ft_philosay, "is thinking", 0) == DEATH)
		return (DEATH);
	return (SUCCESS);
}

static void	philostart(t_philo *philo)
{
	sem_wait(philo->meal);
	sem_wait(philo->start);
	sem_post(philo->start);
	sem_wait(philo->micro);
	sem_post(philo->micro);
	gettimeofday(&(philo->current_time), 0);
	gettimeofday(&(philo->last_meal), 0);
}

static int	philotakefork(t_philo *philo, int start)
{
	if (philo->number % 2 && philo->number != philo->pop)
	{
		if (ft_philofork(philo, 0) == FAIL)
			return (FAIL);
	}
	else if (start && philo->number % 2 == 0)
	{
		if (ft_philofork(philo, 1600) == FAIL)
			return (FAIL);
	}
	else if (ft_philofork(philo, 1641) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	*rt_philo(void *param)
{
	t_philo	*philo;
	int		start;
	int		(*try)(t_philo *, void (*f)(t_philo *, char *, int), char *, int);

	philo = param;
	try = philo->try;
	philostart(philo);
	start = 1;
	while (1)
	{
		if (philotakefork(philo, start) == FAIL)
			break ;
		if (philoeat(philo, try) == DEATH)
			break ;
	}
	if (philo->smeals < 0 || philo->meals < philo->smeals || (philo->meals <= 1
			&& philo->smeals == 0))
		sem_post(philo->meal);
	return (0);
}

// if (start && philo->number % 2 && philo->number != philo->pop
// 	&& ft_philofork(philo, 0, try) == DEATH)
// 	break ;
// else if (start && philo->number % 2 == 0 && ft_philofork(philo, 100,
// 		try) == DEATH)
// 	break ;
// else if (start && ft_philofork(philo, 113, try) == DEATH)
// 	break ;