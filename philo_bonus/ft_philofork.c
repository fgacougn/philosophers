/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philofork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:48:34 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 14:20:28 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_philofork(t_philo *philo, int wt)
{
	usleep(wt);
	sem_wait(philo->forks);
	gettimeofday(&(philo->current_time), 0);
	if (philo->try(philo, &ft_philosay, "has taken a fork", 0) == DEATH)
	{
		sem_post(philo->forks);
		return (FAIL);
	}
	sem_wait(philo->forks);
	gettimeofday(&(philo->current_time), 0);
	return (philo->try(philo, &ft_philosay, "has taken a fork", 0));
}

// int	ft_philofork(t_philo *philo, int wt, int (*try)(struct s_philo *,
// 			void (*f)(struct s_philo *, char *, int), char *, int))
// {
// 	usleep(wt);
// 	if (philo->number == philo->pop)
// 	{
// 		sem_wait(philo->right_fork);
// 		gettimeofday(&(philo->current_time), 0);
// 		if (try(philo, &ft_philosay, "has taken a fork", 0) == DEATH)
// 		{
// 			sem_wait(philo->right_fork);
// 			return (DEATH);
// 		}
// 		sem_wait(philo->left_fork);
// 		gettimeofday(&(philo->current_time), 0);
// 		if (try(philo, &ft_philosay, "has taken a fork", 0) == DEATH)
// 		{
// 			sem_wait(philo->left_fork);
// 			sem_wait(philo->right_fork);
// 			return (DEATH);
// 		}
// 	}
// 	else
// 	{
// 		sem_wait(philo->left_fork);
// 		gettimeofday(&(philo->current_time), 0);
// 		if (try(philo, &ft_philosay, "has taken a fork", 0) == DEATH)
// 		{
// 			sem_wait(philo->left_fork);
// 			return (DEATH);
// 		}
// 		sem_wait(philo->right_fork);
// 		gettimeofday(&(philo->current_time), 0);
// 		if (try(philo, &ft_philosay, "has taken a fork", 0) == DEATH)
// 		{
// 			sem_wait(philo->left_fork);
// 			sem_wait(philo->right_fork);
// 			return (DEATH);
// 		}
// 	}
// 	return (SUCCESS);
// }
