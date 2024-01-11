/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:59:18 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 14:39:48 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	philoeat(t_philo *philo, int (*try)(struct s_philo *,
			void (*f)(struct s_philo *, char *, int), char *, int))
{
	if (try(philo, &ft_philosay, "is eating", 0) == DEATH)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (DEATH);
	}
	ft_memcpy(&(philo->last_meal), &(philo->current_time),
		sizeof(struct timeval));
	philo->meals++;
	if (philo->smeals >= 0 && philo->meals == philo->smeals)
		pthread_mutex_unlock(philo->meal);
	if ((philo->meals == 1 && philo->smeals == 0))
	{
		pthread_mutex_unlock(philo->meal);
		philo->meals++;
	}
	usleep(1000 * philo->eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (try(philo, &ft_philosay, "is sleeping", philo->sleep) == DEATH)
		return (DEATH);
	usleep(1000 * philo->sleep);
	if (try(philo, &ft_philosay, "is thinking", 0) == DEATH)
		return (DEATH);
	return (SUCCESS);
}

static void	philostart(t_philo *philo)
{
	pthread_mutex_lock(philo->meal);
	pthread_mutex_lock(philo->start);
	pthread_mutex_unlock(philo->start);
	pthread_mutex_lock(philo->micro);
	pthread_mutex_unlock(philo->micro);
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
		if (ft_philofork(philo, 800) == FAIL)
			return (FAIL);
	}
	else if (ft_philofork(philo, 841) == FAIL)
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
		pthread_mutex_unlock(philo->meal);
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