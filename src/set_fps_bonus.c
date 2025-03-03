/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fps_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:59:49 by abonifac          #+#    #+#             */
/*   Updated: 2025/03/03 22:23:23 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

/*
	One problem I had on so_long was that the mlx_loop hook was running too fast.
	To fix this, I had to implement a dynamic sleep time.
*/
/*
		The tv argument is a struct timeval (as specified in <sys/time.h>):

			struct timeval {
				time_t      tv_sec;     seconds
				suseconds_t tv_usec;    microseconds
			};
		There is 1 000 000 microseconds in a second.
*/

long long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
/*
	Measure the CPU speed by counting the number of iterations in a second.
	Once 1000ms have passed, return the number of iterations.
*/
int	measure_cpu_speed(void)
{
	long long	start;
	long long	now;
	int			iterations;

	start = current_time();
	now = start;
	iterations = 0;
	while (now - start < 1000)
	{
		iterations++;
		now = current_time();
	}
	return (iterations);
}

/*
	Initialize the dynamic sleep time at the frame rate of X fps.
	1 000 000 / 24 = 41 666.6micro s
	1 000 000 / 60 = 16 666.6micro s
*/
long	init_dynamic_sleep(void)
{
	int		target_fps;
	int		cpu_speed;
	long	sleep_time;

	cpu_speed = measure_cpu_speed();
	target_fps = FRAME_RATE;
	sleep_time = (1000000 / target_fps) - (1000000 / cpu_speed);
	if (sleep_time < 1000)
		sleep_time = 1000;
	return (sleep_time);
}

/*
	Loop the game with a dynamic sleep time.
*/
int	game_loop(t_game *game)
{
	usleep(game->dynamic_sleep_time);
	animate_enemies(game);
	return (0);
}