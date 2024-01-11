/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restaurant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:29:39 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 15:33:02 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static double	philostart(t_philo *philo)
{
	double	dift;

	gettimeofday(&(philo->current_time), 0);
	dift = (-philo->last_meal.tv_sec + philo->current_time.tv_sec) * 1000
		+ (-philo->last_meal.tv_usec + philo->current_time.tv_usec) / 1000;
	pthread_mutex_lock(philo->ankou);
	pthread_mutex_lock(philo->closing);
	return (dift);
}

static int	philoend(t_philo *philo)
{
	pthread_mutex_lock(philo->closing);
	if (*(philo->last_call) != 0)
	{
		pthread_mutex_unlock(philo->closing);
		return (DEATH);
	}
	pthread_mutex_unlock(philo->closing);
	return (SUCCESS);
}

static void	philodo(t_philo *philo, char *str, void (*f)(t_philo *, char *,
			int))
{
	pthread_mutex_unlock(philo->ankou);
	pthread_mutex_unlock(philo->closing);
	f(philo, str, 0);
}

static void	philomute(t_philo *philo, double dift)
{
	if (((double)philo->die - dift) >= 0)
		usleep(1000 * ((double)philo->die - dift));
	pthread_mutex_unlock(philo->ankou);
	pthread_mutex_unlock(philo->closing);
}

int	ft_restaurant(t_philo *philo, void (*f)(t_philo *, char *, int), char *str,
		int time)
{
	double	dift;

	dift = philostart(philo);
	if (dift + (double)time <= philo->die && *(philo->parcae) == 0
		&& *(philo->last_call) == 0)
		philodo(philo, str, f);
	else if (*(philo->last_call) == 0)
	{
		pthread_mutex_unlock(philo->ankou);
		pthread_mutex_unlock(philo->closing);
		f(philo, str, 0);
		if (((double)philo->die - dift) >= 0)
			usleep(1000 * ((double)philo->die - dift));
		pthread_mutex_lock(philo->ankou);
		*(philo->parcae) = 1;
		pthread_mutex_unlock(philo->ankou);
		gettimeofday(&(philo->current_time), 0);
		ft_philosay(philo, "died", 1);
		return (DEATH);
	}
	else
		philomute(philo, dift);
	return (philoend(philo));
}
