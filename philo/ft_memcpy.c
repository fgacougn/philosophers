/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:50:02 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:50:04 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*str2;

	if (dest == src)
		return (dest);
	str = (char *)dest;
	str2 = (char *)src;
	while (n--)
		*str++ = *str2++;
	return (dest);
}
