NAME        = so_long

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = includes
LIBFT_DIR   = libft
MLX_DIR     = mlx

SRC_FILES        = main.c map_info.c free_game.c init_structs.c \
				load_digit.c score.c load_textures.c load_textures2.c \
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

test: $(NAME)
	-valgrind ./$(NAME) maps/flood_fill_line.ber
	-valgrind ./$(NAME) maps/line_len_prob.ber
	-valgrind ./$(NAME) maps/map_flood_fill.ber
	-valgrind ./$(NAME) maps/map_invalid_char.ber
	-valgrind ./$(NAME) maps/map_no_collect.ber
	-valgrind ./$(NAME) maps/not_rect.ber
	-valgrind ./$(NAME) maps/map_too_small.ber
	-valgrind ./$(NAME) maps/line_1_empty.ber
	-valgrind ./$(NAME) maps/file_empty.ber

re: fclean all

.PHONY: all clean fclean re libft test