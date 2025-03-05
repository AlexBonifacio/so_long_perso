/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:43:19 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/05 13:48:30 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stddef.h>

int	is_valid_char(char c)
{
	return (c == '0' || c == 'E' || c == 'C' || c == '1' || c == 'P'
		|| c == 'V');
}

int	check_arg(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		w_error("Error: wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b'
		|| argv[1][i - 4] != '.')
	{
		w_error("Error: wrong file extension\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}
