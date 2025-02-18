/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:57:38 by abonifac          #+#    #+#             */
/*   Updated: 2025/01/29 15:57:40 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr(const char *s)
{
	ssize_t		len;
	ssize_t		w_bytes;

	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	len = ft_strlen(s);
	w_bytes = 0;
	w_bytes = write(1, s, len);
	if (w_bytes != len)
	{
		write(2, "Error: write fail\n", 18);
		return (-1);
	}
	return (w_bytes);
}
