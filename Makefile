NAME        = so_long

# Répertoires
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = includes
LIBFT_DIR   = libft
MLX_DIR     = mlx

# Recherche de tous les fichiers sources dans SRC_DIR
SRC_FILES        = main.c count_in_map.c check_nb_assets.c free_game.c \
				init_structs.c map_line_len.c load_digit.c score.c \
				ft_print_error.c load_textures.c


SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Transformation des fichiers .c en fichiers .o dans OBJ_DIR
OBJ         = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Options du compilateur
CC          = cc
CFLAGS      = -g3 -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Bibliothèques
LIBFT       = $(LIBFT_DIR)/libft.a
MLX_LIB     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME)

# Compilation de chaque fichier source en objet
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Construction de la libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re