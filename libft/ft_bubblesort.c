/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:21:13 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/16 23:08:20 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesort(int *tab, int tab_size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < tab_size - 1)
	{
		j = 0;
		while (j < tab_size - 1 - i)
		{
			if (tab[j] > tab [j + 1])
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}
