CC = clang

FLAGS = -std=gnu17 -Wall -Werror -Wextra -Wpedantic -Weverything

INCLUDE = -I ./inc

NAME = raytracing

OBJ = $(sort $(addsuffix .o, $(basename $(SRC))))

SRC = \
	./src/main.c \
	./src/command_argument.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
