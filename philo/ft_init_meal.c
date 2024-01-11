/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_meal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:16:09 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/11 14:25:30 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_init_meal(t_env *env)
{
	int	i;

	env->philos = malloc(env->pop * sizeof(pthread_t));
	if (!env->philos)
		return (ERR_MALLOC);
	i = 0;
	while (i < env->pop)
	{
		pthread_create(&(env->philos[i]), 0, &rt_philo, &(env->party[i]));
		i++;
	}
	if (env->meals >= 0)
		pthread_create(&(env->waiter), 0, &rt_waiter, env);
	return (SUCCESS);
}
