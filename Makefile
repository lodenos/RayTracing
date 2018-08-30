CC = clang

FLAGS = -std=gnu17 -Wall -Werror -Wextra -Wpedantic -Weverything

INCLUDE = -I ./inc

LINKER = -lOpenCL -lSDL2 -lm

NAME = raytracing

OBJ = $(sort $(addsuffix .o, $(basename $(SRC))))

SRC = \
	./src/main_loop.c \
	./src/main.c \
	./src/ray_tracing.c \
	./src/device/detect_device_gpu.c \
	./src/event/event_capture.c \
	./src/parser/command_argument.c \
	./src/parser/load_file_ort.c \
	./src/primitive/intersection.c \
	./src/primitive/sphere.c \
	./src/shader/flat_shading.c \
	./src/shader/shadow_mapping.c \
	./src/vector/add.c \
	./src/vector/dot.c \
	./src/vector/intersection_point.c \
	./src/vector/normalize.c \
	./src/vector/sub.c \
	./src/video/camera.c \
	./src/video/launcher_main_window.c \
	./src/video/pixel_HDR_sRGB.c

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
