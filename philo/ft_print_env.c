/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:54:20 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/09 12:08:07 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_print_env(t_env *env)
{
	int	i;

	write(STDOUT_FILENO, "POP ", 4);
	ft_putnbr_fd(env->pop, STDOUT_FILENO);
	write(STDOUT_FILENO, " DIE ", 5);
	ft_putnbr_fd(env->die, STDOUT_FILENO);
	write(STDOUT_FILENO, " EAT ", 5);
	ft_putnbr_fd(env->eat, STDOUT_FILENO);
	write(STDOUT_FILENO, " SLEEP ", 7);
	ft_putnbr_fd(env->sleep, STDOUT_FILENO);
	write(STDOUT_FILENO, " MEALS ", 7);
	ft_putnbr_fd(env->meals, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	i = 0;
	while (i < env->pop)
	{
		write(STDOUT_FILENO, "\tPhilosoper ", 12);
		ft_putnbr_fd(env->party[i].number, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
