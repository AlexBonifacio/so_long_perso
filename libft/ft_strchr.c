/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:29:41 by abonifac          #+#    #+#             */
/*   Updated: 2024/12/07 10:49:39 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_return;

	s_return = (char *)s;
	c = (unsigned char) c;
	while (*s_return != '\0' && c != *s_return)
	{
		s_return++;
	}
	if (*(unsigned char *)s_return == (unsigned char)c)
		return (s_return);
	return (NULL);
}
