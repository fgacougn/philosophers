/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_meal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:23:50 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/09 15:36:48 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_start_meal(t_env *env)
{
	int	i;

	i = 0;
	gettimeofday(&(env->start_time), 0);
	while (i < env->pop)
	{
		ft_memcpy(&(env->party[i].last_meal), env->party[i].start_time,
			sizeof(env->party[i].last_meal));
		i++;
	}
	i = 0;
	pthread_mutex_unlock(&(env->start));
	if (env->meals >= 0)
		pthread_join((env->waiter), 0);
	while (i < env->pop)
	{
		pthread_join(env->philos[i], 0);
		i++;
	}
}
