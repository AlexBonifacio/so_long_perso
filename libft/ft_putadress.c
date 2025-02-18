/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:55:30 by abonifac          #+#    #+#             */
/*   Updated: 2025/01/29 15:29:13 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putptr(unsigned long n)
{
	size_t	i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 1;
	if (n >= 16)
	{
		i += ft_putptr(n / 16);
	}
	ft_putchar(hex[n % 16]);
	return (i);
}

size_t	ft_adress(void *ptr)
{
	size_t	i;

	i = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_putptr((unsigned long)ptr);
	return (i);
}
