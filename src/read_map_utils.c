/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:16:44 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/08 20:59:57 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	check_line(char **map)
{
	int	i;
	int	len;
	int	len_comp;

	i = 0;
	len_comp = 0;
	len = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		len_comp = ft_strlen(map[i]);
		if (len != len_comp)
		{
			w_error("Error: Different line size\n");
			free_tab(map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_double_n(char *temp)
{
	int	i;

	i = 0;
	while (temp[i + 1])
	{
		if (temp[i] == '\n' && temp[i + 1] == '\n')
		{
			w_error("Error: Horizontale space in map\n");
			free(temp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_strlen_n_error(char *file_content)
{
	w_error("Error: Something wrong with lines\n");
	free(file_content);
	exit(EXIT_FAILURE);
}

char	*create_counter_line(char *string)
{
	char	*counter;
	int		i;
	int		max_len;

	max_len = ft_strlen(string);
	counter = malloc(sizeof(char) * (max_len + 1));
	if (!counter)
		return (NULL);
	counter[0] = 'H';
	counter[1] = 'D';
	counter[2] = 'U';
	i = 3;
	while (i < max_len)
	{
		counter[i] = '1';
		i++;
	}
	counter[i] = '\0';
	return (counter);
}
