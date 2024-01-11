/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:54:24 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/10 14:50:00 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_philosay(t_philo *philo, char *str, int opt)
{
	sem_wait(philo->micro);
	sem_wait(philo->ankou);
	if (*(philo->parcae) == 0 || (opt == 1 && *(philo->snip) == 0) || opt == 2)
		printf("%ld %d %s\n", (philo->current_time.tv_sec
				- philo->start_time->tv_sec) * 1000
			+ (philo->current_time.tv_usec - philo->start_time->tv_usec) / 1000,
			philo->number, str);
	if (opt == 1)
		*(philo->snip) = 1;
	sem_post(philo->micro);
	sem_post(philo->ankou);
}
