/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:59:43 by abonifac          #+#    #+#             */
/*   Updated: 2025/01/29 16:00:33 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_conv(const char format, va_list *args)
{
	char	*hex_lower;
	char	*hex_upper;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'i' || format == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), hex_lower));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), hex_upper));
	else if (format == 'p')
		return (ft_adress(va_arg(*args, void *)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	next_isinset(char *c)
{
	if (*c == '\0')
		return (0);
	c++;
	if (*c == 's' || *c == 'd' || *c == 'i' || *c == 'c' || *c == 'u'
		|| *c == 'x' || *c == 'X' || *c == 'p' || *c == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && next_isinset((char *)&str[i]))
		{
			count += is_conv(str[i + 1], &args);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
