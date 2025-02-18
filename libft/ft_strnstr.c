/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:46:06 by abonifac          #+#    #+#             */
/*   Updated: 2024/12/06 16:15:20 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	trig;
	size_t	i;

	if (*little == 0)
		return ((char *)big);
	if (size == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < size)
	{
		if (big[i] == little[0])
		{
			trig = 0;
			while (big[i + trig] == little[trig] && big[i + trig]
				&& little[trig] && (i + trig) < size)
			{
				trig++;
				if (little[trig] == '\0')
					return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}
