/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:47:32 by abonifac          #+#    #+#             */
/*   Updated: 2024/12/07 10:43:19 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem_block, int search_c, size_t size)
{
	unsigned char	*s;

	s = (unsigned char *) mem_block;
	search_c = (unsigned char) search_c;
	while (size != 0)
	{
		if (*s == search_c)
			return (s);
		s++;
		size--;
	}
	return (NULL);
}
