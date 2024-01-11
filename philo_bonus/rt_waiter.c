/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_waiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:49:37 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 14:17:38 by fgacougn         ###   ########.fr       */
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
		sem_wait(&(env->cptmeals));
		i++;
	}
	sem_wait(&(env->closing));
	env->lastcall = 1;
	sem_post(&(env->closing));
	i = 0;
	while (i < env->pop)
	{
		sem_post(&(env->cptmeals));
		i++;
	}
	return (0);
}
