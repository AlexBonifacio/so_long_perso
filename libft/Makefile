# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 00:40:59 by abonifac          #+#    #+#              #
#    Updated: 2025/02/18 00:38:00 by abonifac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRCS = ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_striteri.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
			ft_printf.c ft_putchar.c ft_putadress.c ft_putnbr.c ft_putnbr_base.c \
			ft_putnbr_u.c ft_putstr.c ft_atol.c ft_print_list.c ft_lstclear.c \
			ft_bubblesort.c ft_realloc.c
			
OBJ_DIR = obj
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
EX = *.out

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:%.c libft.h Makefile | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

clean:
			@rm -f $(OBJ) $(EX) *.md

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all re fclean clean