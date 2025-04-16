NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS_DIR = libft_objects

SOURCES_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_isspace.c ft_atol.c ft_atof.c

BSOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

PRINTF_SOURCES = $(addprefix ./printf/, ft_printf.c print_chars_strs.c printhex.c \
					printnbrs.c )
GNL_SOURCES = $(addprefix ./get_next_line/, get_next_line_bonus.c \
			get_next_line_utils_bonus.c get_next_line_utils.c get_next_line.c )

OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES_FILES:.c=.o))
BOBJECTS = $(addprefix $(OBJECTS_DIR)/, $(BSOURCES:.c=.o))
PRINTFOBJECTS = $(addprefix $(OBJECTS_DIR)/, $(notdir $(PRINTF_SOURCES:.c=.o)))
GNL_OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(notdir $(GNL_SOURCES:.c=.o)))

all: $(NAME)

$(NAME): $(OBJECTS) $(BOBJECTS) $(PRINTFOBJECTS) $(GNL_OBJECTS)
	@ar rcs $@ $^

$(OBJECTS_DIR)/%.o: %.c | $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)/%.o: ./printf/%.c | $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR)/%.o: ./get_next_line/%.c | $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

bonus: $(BOBJECTS) $(NAME)
	@ar rcs $(NAME) $(BOBJECTS)

clean:
	@rm -rf $(OBJECTS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re