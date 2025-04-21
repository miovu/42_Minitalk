NAME = minitalk

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

FILES = bah.c	

OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(FILES:.c=.o))
OBJECTS_DIR = objects
SRC_DIR = srcs

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./includes/libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) 
	@echo "Building..."
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	@echo "Ready!"

$(OBJECTS_DIR)/%.o: $(FILES)/%.c | $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus -s --no-print-directory

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

clean:
	@rm -rf $(OBJECTS_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@echo "Cleaned!"

fclean: clean
	@make -C $(LIBFT_DIR) fclean -s --no-print-directory
	@rm -rf $(NAME)

re: fclean all
	@echo "Rebuilt!"

.PHONY: all clean fclean re