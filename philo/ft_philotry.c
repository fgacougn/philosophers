/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philotry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:51:07 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 15:33:18 by fgacougn         ###   ########.fr       */
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
	return (dift);
}

static void	philodo(t_philo *philo, char *str, void (*f)(t_philo *, char *,
			int))
{
	pthread_mutex_unlock(philo->ankou);
	f(philo, str, 0);
}

int	ft_philotry(t_philo *philo, void (*f)(t_philo *, char *, int), char *str,
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
	return (SUCCESS);
}

// double	dift;
// int		i;

// gettimeofday(&(philo->current_time), 0);
// dift = (-philo->last_meal.tv_sec + philo->current_time.tv_sec) * 1000
// 	+ (-philo->last_meal.tv_usec + philo->current_time.tv_usec) / 1000;
// pthread_mutex_lock(philo->ankou);
// if (dift + (double)time <= philo->die && *(philo->parcae) == 0)
// {
// 	pthread_mutex_unlock(philo->ankou);
// 	f(philo, str, 0);
// }
// else
// {
// 	pthread_mutex_unlock(philo->ankou);
// 	if (1000 * ((double)philo->die - dift) > 0)
// 	{
// 		f(philo, str, 0);
// 		usleep(1000 * ((double)philo->die - dift));
// 	}
// 	pthread_mutex_lock(philo->ankou);
// 	*(philo->parcae) = 1;
// 	pthread_mutex_unlock(philo->ankou);
// 	gettimeofday(&(philo->current_time), 0);
// 	ft_philosay(philo, "died", 1);
// 	i = 0;
// 	return (DEATH);
// }
// return (SUCCESS);
