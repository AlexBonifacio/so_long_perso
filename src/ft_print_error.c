/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:20:02 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/28 15:12:46 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	w_error(char *msg)
{
	if (write(2, msg, ft_strlen(msg)) == -1)
		write(2, "Error: write() failed\n", 22);
}
