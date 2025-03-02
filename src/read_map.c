/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:07:52 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/01 23:51:17 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"


static void	*fill_temp(char *temp, char *line, int fd)
{
	char	*old_temp;

	old_temp = NULL;
	while ((line = get_next_line(fd)))
	{
		old_temp = temp;
		temp = ft_strjoin(temp, line);
		free(old_temp);
		free(line);
		if (!temp)
			return (NULL);
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
	map = ft_split(temp, '\n');
	free(temp);
	return (map);
}