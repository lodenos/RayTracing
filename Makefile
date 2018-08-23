CC = clang

FLAGS = -std=gnu17 -Wall -Werror -Wextra -Wpedantic -Weverything

INCLUDE = -I ./inc

LINKER = -lOpenCL -lSDL2

NAME = raytracing

OBJ = $(sort $(addsuffix .o, $(basename $(SRC))))

SRC = \
	./src/main.c \
	./src/command_argument.c \
	./src/detect_device_gpu.c \
	./src/event_capture.c \
	./src/launcher_main_window.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LINKER) -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
