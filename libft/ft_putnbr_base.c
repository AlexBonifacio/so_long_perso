/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:47 by abonifac          #+#    #+#             */
/*   Updated: 2025/01/29 15:32:48 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_base(unsigned int uint_n, char *base)
{
	size_t	i;
	size_t	base_count;	
	char	*hex;

	hex = base;
	base_count = ft_strlen(hex);
	if (base_count < 2)
	{
		return (0);
	}
	i = 1;
	if (uint_n >= base_count)
	{
		i += ft_putnbr_base(uint_n / base_count, base);
	}
	ft_putchar(hex[uint_n % base_count]);
	return (i);
}
