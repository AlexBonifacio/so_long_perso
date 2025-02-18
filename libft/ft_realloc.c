/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:09:46 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/17 22:50:55 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *buffer, size_t new_size, size_t old_size)
{
	void	*new_buffer;

	if (new_size == 0)
	{
		free (buffer);
		return (NULL);
	}
	if (buffer == NULL)
		return (malloc(new_size));
	new_buffer = malloc(new_size);
	if (!new_buffer)
		return (NULL);
	if (old_size > new_size)
		old_size = new_size;
	ft_memcpy(new_buffer, buffer, old_size);
	free(buffer);
	return (new_buffer);
}
