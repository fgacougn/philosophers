/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:04:19 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/02 15:05:58 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_print_philo(t_philo *philo)
{
	write(STDOUT_FILENO, "NUMBER ", 7);
	ft_putnbr_fd(philo->number, STDOUT_FILENO);
	write(STDOUT_FILENO, " DIE ", 5);
	ft_putnbr_fd(philo->die, STDOUT_FILENO);
	write(STDOUT_FILENO, " EAT ", 5);
	ft_putnbr_fd(philo->eat, STDOUT_FILENO);
	write(STDOUT_FILENO, " SLEEP ", 7);
	ft_putnbr_fd(philo->sleep, STDOUT_FILENO);
	write(STDOUT_FILENO, " MEALS ", 7);
	ft_putnbr_fd(philo->meals, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
}
