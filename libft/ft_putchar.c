/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:32:56 by abonifac          #+#    #+#             */
/*   Updated: 2025/01/29 15:26:29 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	int	w_bytes;

	w_bytes = 0;
	w_bytes = write(1, &c, 1);
	if (w_bytes == -1)
	{
		write(2, "Error : write fail", 18);
		return (-1);
	}
	return (w_bytes);
}
