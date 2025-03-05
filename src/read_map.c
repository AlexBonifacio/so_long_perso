/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:07:52 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/05 17:11:52 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	*fill_temp(char *temp, char *line, int fd)
{
	char	*old_temp;

	old_temp = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		old_temp = temp;
		temp = ft_strjoin(temp, line);
		free(old_temp);
		free(line);
		if (!temp)
			return (NULL);
		line = get_next_line(fd);
	}
	line = add_counter(temp);
	if (!line)
		return (return_null_free(&temp));
	old_temp = temp;
	temp = ft_strjoin(temp, line);
	free(line);
	free(old_temp);
	if (!temp)
		return (NULL);
	return (temp);
}

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
			w_error("Line error\n");
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
			w_error("Error: Double backslash\n");
			free(temp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

char	**load_map(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	char	**map;

	fd = open(filename, O_RDONLY);
	fd_error(fd);
	line = NULL;
	temp = ft_strdup("");
	if (!temp)
		return (NULL);
	temp = fill_temp(temp, line, fd);
	if (!temp)
		return (return_null_free(&temp));
	close(fd);
	check_double_n(temp);
	map = ft_split(temp, '\n');
	free(temp);
	check_line(map);
	return (map);
}
