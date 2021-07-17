NAME := cub
CC := clang
SANIT := -g -fsanitize=address
CFLAGS := -Wall -Wextra -Werror

LIB_DIRS := libft Libft2D
LIB_PATH = $(addprefix libs/, $(LIB_DIRS))
LIB := $(foreach dir, $(LIB_PATH), $(wildcard $(dir)/*.a))

INC_PATH := $(LIB_PATH) include
INC := $(addprefix -I , $(INC_PATH))

SRC_DIR := settings
SRC_PATH := $(addprefix srcs/, $(SRC_DIR)) srcs
SRC := $(foreach dir, $(SRC_PATH), $(wildcard $(dir)/*.c))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SANIT) main.c $(SRC) $(LIB) $(INC) -o $@

# build:
# 	clang main.c -g -I libx -L libx -lm -lbsd -lmlx -lXext -lX11

run: $(NAME)
	@./cub

clean:
	$(RM) *.out

fclean: clean
	$(RM) $(NAME)

re: fclean all
