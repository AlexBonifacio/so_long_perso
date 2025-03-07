/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:07:52 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/07 19:36:21 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

char	*read_file_content(char *filename)
{
	int		fd;
	char	*line;
	char	*old_temp;
	char	*temp;

	temp = ft_strdup("");
	if (!temp)
		return (NULL);
	fd = open(filename, O_RDONLY);
	fd_error(fd, temp);
	line = get_next_line(fd);
	while (line != NULL)
	{
		old_temp = temp;
		temp = ft_strjoin(temp, line);
		free(old_temp);
		free(line);
		if (!temp)
			close(fd);
		if (!temp)
			return (NULL);
		line = get_next_line(fd);
	}
	close(fd);
	return (temp);
}

char	**load_map(char *filename)
{
	char	*file_content;
	char	**map;
	char	*counter_line;

	file_content = read_file_content(filename);
	if (!file_content || ft_strlen_n(file_content) == 0)
		ft_strlen_n_error(file_content);
	check_double_n(file_content);
	map = ft_split(file_content, '\n');
	free(file_content);
	if (!map)
		return (NULL);
	check_line(map);
	counter_line = create_counter_line(map[0]);
	if (!counter_line)
	{
		free_tab(map);
		exit(EXIT_FAILURE);
	}
	map = append_counter_line(map, counter_line);
	return (map);
}
