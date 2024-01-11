/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:30:49 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 15:30:49 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	signe;
	int	retour;

	signe = 1;
	if (!nptr || !*nptr)
		return (0);
	while (*nptr == ' ' || (*nptr <= 13 && *nptr >= 9))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	retour = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		retour *= 10;
		retour += *nptr - '0';
		nptr++;
	}
	return (retour * signe);
}
