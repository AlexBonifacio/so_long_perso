/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:19:22 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/20 01:43:43 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "libft.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>


typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;


int main(void)
{
	void	*mlx;
	// void	*mlx_win;
	int fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (1);
	char *line;
	while ((line = get_next_line(fd)))
	{
		ft_printf("%s\n", line);
		free(line);
	}
	

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "HELLO");
	mlx_loop(mlx);
	
}