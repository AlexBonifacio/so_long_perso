/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:38:17 by abonifac          #+#    #+#             */
/*   Updated: 2024/12/06 16:14:03 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	unsigned char	*pointer1;
	unsigned char	*pointer2;

	pointer1 = (unsigned char *)ptr1;
	pointer2 = (unsigned char *)ptr2;
	if (size == 0)
		return (0);
	while (size - 1 > 0)
	{
		if (*pointer1 != *pointer2)
			return (*pointer1 - *pointer2);
		pointer1++;
		pointer2++;
		size--;
	}
	return (*pointer1 - *pointer2);
}
