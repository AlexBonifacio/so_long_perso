/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:10:17 by abonifac          #+#    #+#             */
/*   Updated: 2024/12/07 10:48:38 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_move;
	const unsigned char	*src_move;
	size_t				n_move;

	if (!dest && !src)
		return (NULL);
	dest_move = (unsigned char *)dest;
	src_move = (const unsigned char *)src;
	n_move = n;
	if ((src_move + n_move) > dest_move && src_move < dest_move)
	{
		dest_move = dest_move + n - 1;
		src_move = src_move + n - 1;
		while (n_move--)
			*dest_move-- = *src_move--;
	}
	else
	{
		while (n_move--)
			*dest_move++ = *src_move++;
	}
	return (dest);
}
