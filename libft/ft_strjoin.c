/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:19:43 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/07 19:44:00 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	size_t	pos;
	char	*s;

	if (SIZE_MAX - ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc((total_len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	pos = 0;
	while (s1[i])
	{
		s[pos++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		s[pos++] = s2[i++];
	}
	s[total_len] = '\0';
	return (s);
}
