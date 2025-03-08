NAME        = so_long

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = includes
LIBFT_DIR   = libft
MLX_DIR     = mlx

SRC_FILES        = main.c map_check.c free_game.c init_structs.c \
				load_digit.c score.c load_textures.c load_exit.c \
				keys_handler.c load_ennemy.c so_long_utils.c read_map.c \
				render.c so_long_utils2.c move.c ennemy_animation.c \
				set_fps_bonus.c check_map_walls.c flood_fill.c \
				so_long_utils3.c read_map_utils.c
 

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ         = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC          = cc
CFLAGS      = -g3 -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT       = $(LIBFT_DIR)/libft.a
MLX_LIB     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR) all

$(NAME): $(OBJ) $(LIBFT)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(INC_DIR)/so_long.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) 
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft test

#MAPS_DIR ?= maps_err
#MAPS = $(wildcard $(MAPS_DIR)/*.ber)
#LOG_FILE = valgrind_log.txt
#
#test: $(NAME)
#	@echo "=== Démarrage des tests Valgrind ===" > $(LOG_FILE)
#	@for file in $(MAPS); do \
#		echo "Test sur $$file" >> $(LOG_FILE); \
#		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 --track-fds=all ./$(NAME) $$file 2>&1 | grep -v -E "For lists|Memcheck|Open file descriptor|For list of|Memcheck,|Using|<inherited|Copyright" >> $(LOG_FILE); \
#		echo "-------------------------" >> $(LOG_FILE); \
#	done
#	@echo "=== Fin des tests Valgrind ===" >> $(LOG_FILE)
#	@cat $(LOG_FILE)
