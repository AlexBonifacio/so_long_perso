/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:22:49 by abonifac          #+#    #+#             */
/*   Updated: 2024/12/07 10:45:08 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*byte;
	size_t			i;

	byte = (unsigned char *)pointer;
	i = 0;
	while (i != count)
	{
		byte[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
