/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_assets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:50:07 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/27 14:00:18 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"


int	check_nb_assets(t_game *game)
{
	if (count_in_map(game, 'P') != 1 || count_in_map(game, 'E') != 1)
	{
		ft_printf("Error: too many players or exit\n");
		free_map(game);
		exit(EXIT_FAILURE);
		return (0);
	}
	return (1);
}

