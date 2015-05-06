CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = recherche
DIR_OBJ = objects
SRC = recherche.c dead_links.c yesterday_changes.c command.c
OBJ = $(patsubst %.c, $(DIR_OBJ)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

$(DIR_OBJ)/%.o: %.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
