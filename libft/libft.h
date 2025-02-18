/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:25:04 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/17 22:52:40 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h> 
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_node
{
	void			*value;
	struct s_node	*next;
}	t_node;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *mem_block, int search_c, size_t size);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *first, const char *second, size_t length);
char	*ft_strnstr(const char *big, const char *little, size_t size);
char	*ft_strrchr(const char *s, int s_char);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);

/*ft_printf*/
int		ft_putchar(char c);
size_t	ft_adress(void *ptr);
size_t	ft_putnbr(int n);
size_t	ft_putnbr_base(unsigned int uint_n, char *base);
size_t	ft_putnbr_u(unsigned int uint_n);
ssize_t	ft_putstr(const char *s);
int		ft_printf(const char *str, ...);

/*linked list*/
void	ft_print_list(t_node *list);
void	ft_lstclear(t_node **lst);

/*others*/
long	ft_atol(const char *str);
void	ft_bubblesort(int *tab, int tab_size);
void	*ft_realloc(void *buffer, size_t new_size, size_t old_size);

#endif