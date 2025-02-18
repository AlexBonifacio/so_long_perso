/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:45:37 by abonifac          #+#    #+#             */
/*   Updated: 2025/01/29 15:33:32 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_u(unsigned int uint_n)
{
	size_t	i;

	i = 1;
	if (uint_n >= 10)
	{
		i += ft_putnbr_u(uint_n / 10);
	}
	ft_putchar((uint_n % 10) + '0');
	return (i);
}
