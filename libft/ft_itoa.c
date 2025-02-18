/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:29:18 by abonifac          #+#    #+#             */
/*   Updated: 2024/12/06 16:13:51 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(int n)
{
	long	nbr;
	int		len;

	nbr = n;
	if (nbr > 0)
		len = 0;
	else
	{
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*s;

	nbr = n;
	len = count_int(nbr);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	s[len] = '\0';
	while (nbr > 0)
	{
		s[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n == 0)
		s[0] = '0';
	return (s);
}
