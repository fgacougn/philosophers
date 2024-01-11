/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:54:24 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/09 12:02:09 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_philosay(t_philo *philo, char *str, int opt)
{
	pthread_mutex_lock(philo->micro);
	pthread_mutex_lock(philo->ankou);
	if (*(philo->parcae) == 0 || (opt == 1 && *(philo->snip) == 0) || opt == 2)
		printf("%ld %d %s\n", (philo->current_time.tv_sec
				- philo->start_time->tv_sec) * 1000
			+ (philo->current_time.tv_usec - philo->start_time->tv_usec) / 1000,
			philo->number, str);
	if (opt == 1)
		*(philo->snip) = 1;
	pthread_mutex_unlock(philo->micro);
	pthread_mutex_unlock(philo->ankou);
}
