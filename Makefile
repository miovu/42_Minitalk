CLIENT = client
SERVER = server

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

CLIENT_SRC = client.c
SERVER_SRC = server.c

OBJECTS_DIR = objects
CLIENT_OBJ = $(OBJECTS_DIR)/client.o
SERVER_OBJ = $(OBJECTS_DIR)/server.o

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./includes/libft

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Built client ✅"

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Built server ✅"

$(OBJECTS_DIR)/%.o: %.c | $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🛠️ Compiling"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus -s --no-print-directory

clean:
	@rm -rf $(OBJECTS_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@echo "Cleaned object files 🧽"

fclean: clean
	@make -C $(LIBFT_DIR) fclean -s --no-print-directory
	@rm -rf $(CLIENT) $(SERVER)
	@echo "Fully cleaned! 🧼"

re: fclean all
	@echo "Rebuilt!"

.PHONY: all clean fclean re