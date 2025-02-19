NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iinc -Imlx

RM = rm
RMFLAG = -f

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11


SRCS = \
	src/main.c \
	src/ft_print_error.c

SRC_DIR = src
OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(MLX_LIB) $(OBJ_DIR) $(NAME) 


$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: src/%.c Makefile 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)
	if [ -d "./mlx" ]; then make -C $(MLX_DIR) clean; fi

re: fclean all

.PHONY: all clean run fclean re 