/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:58:32 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/16 23:03:05 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_node *list)
{
	while (list)
	{
		ft_printf("%d -> ", list->value);
		list = list->next;
	}
	ft_printf("NULL\n");
}
