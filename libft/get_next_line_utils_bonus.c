/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:52:16 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/19 22:12:57 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char const *s2, ssize_t l_s1, ssize_t len_s2)
{
	char		*str;
	ssize_t		index_s1;
	ssize_t		index_s2;

	index_s1 = -1;
	index_s2 = -1;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (l_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (++index_s1 < l_s1)
		str[index_s1] = s1[index_s1];
	while ((++index_s2 < len_s2))
	{
		str[index_s1 + index_s2] = s2[index_s2];
		if (s2[index_s2] == '\n')
			break ;
	}
	if (s2[index_s2] == '\n')
		str[index_s1 + index_s2++] = '\n';
	str[index_s1 + index_s2] = '\0';
	return (str);
}
