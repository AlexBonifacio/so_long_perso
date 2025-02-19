/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:47:13 by abonifac          #+#    #+#             */
/*   Updated: 2025/01/26 20:10:22 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FD_MAX
#  define FD_MAX __FD_SETSIZE
# endif

char	*get_next_line(int fd);
ssize_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2, ssize_t len_s1, ssize_t len_s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif