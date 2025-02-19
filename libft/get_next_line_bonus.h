/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:47:13 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/19 22:14:37 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef FD_MAX
#  define FD_MAX __FD_SETSIZE
# endif

# include "libft.h"

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char const *s2, ssize_t l_s1, ssize_t len_s2);
char	*get_next_line(int fd);

#endif