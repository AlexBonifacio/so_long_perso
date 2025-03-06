/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:03:40 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/06 20:00:03 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	display_tab(t_game game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (game.map.map[i])
	{
		y = 0;
		while (game.map.map[i][y])
		{
			ft_printf("%c", game.map.map[i][y]);
			y++;
		}
		i++;
		ft_printf("\n");
	}
}

void	w_error(char *msg)
{
	if (write(2, msg, ft_strlen(msg)) == -1)
		write(2, "Error: write() failed\n", 22);
}

int	map_line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	count_in_map(char **map, char c)
{
	int	count;
	int	i;
	int	y;

	count = 0;
	i = 0;
	y = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == c)
				count++;
			y++;
		}
		i++;
	}
	return (count);
}

void	display_map(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			ft_printf("%c", map[i][y]);
			y++;
		}
		i++;
		ft_printf("\n");
	}
}
