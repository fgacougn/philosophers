/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_waiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:49:37 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 14:21:11 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*rt_waiter(void *param)
{
	t_env	*env;
	int		i;

	i = 0;
	env = param;
	while (i < env->pop)
	{
		pthread_mutex_lock(&(env->cptmeals[i]));
		i++;
	}
	pthread_mutex_lock(&(env->closing));
	env->lastcall = 1;
	pthread_mutex_unlock(&(env->closing));
	i = 0;
	while (i < env->pop)
	{
		pthread_mutex_unlock(&(env->cptmeals[i]));
		i++;
	}
	return (0);
}
