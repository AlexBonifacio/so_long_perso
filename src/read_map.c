/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:07:52 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/06 12:40:42 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"


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
			w_error("Error: Horizontale space in map\n");
			free(temp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

char	*read_file_content(char *filename)
{
	int		fd;
	char	*line;
	char	*old_temp;
	char	*temp;

	fd = open(filename, O_RDONLY);
	fd_error(fd);
	temp = ft_strdup("");
	if (!temp)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		old_temp = temp;
		temp = ft_strjoin(temp, line);
		free(old_temp);
		free(line);
		if (!temp)
		{
			close(fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (temp);
}

int	get_max_len(char **map)
{
	return (ft_strlen(map[0]));
}

int	ft_strlen_n(const char *s, int min_len)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (i < min_len)
		return (0); // La chaîne est trop courte
	return (1);
}

char	**load_map(char *filename)
{
	char	*file_content;
	char	**map;
	char	*counter_line;
	int		max_len;

	file_content = read_file_content(filename);
	if (!file_content || !*file_content)
	{
		free(file_content);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen_n(file_content, 3) == 0)
	{
		w_error("Error: Line 1 is too short\n");
		free(file_content);
		exit(EXIT_FAILURE);
	}
	check_double_n(file_content);
	map = ft_split(file_content, '\n');
	free(file_content);
	check_line(map);
	if (!map)
		return (NULL);
	max_len = get_max_len(map);
	counter_line = create_counter_line(max_len);
	if (!counter_line)
	{
		free_tab(map);
		exit(EXIT_FAILURE);
	}
	map = append_counter_line(map, counter_line);
	return (map);
}
