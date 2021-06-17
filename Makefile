NAME := pamonha
CC := clang
SANIT := -g -fsanitize=address
CFLAGS := -Wall -Wextra -Werror

LIB_PATH = libx libft
LIB := $(foreach dir, $(LIB_PATH), $(wildcard $(dir)/*.a))

INC_PATH := libft include gnl
INC := $(addprefix -I , $(INC_PATH))

SRC_PATH := srcs gnl
SRC := $(foreach dir, $(SRC_PATH), $(wildcard $(dir)/*.c))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SANIT) main.c $(SRC) $(LIB) $(INC) -o $@

# build:
# 	clang main.c -g -I libx -L libx -lm -lbsd -lmlx -lXext -lX11

run: $(NAME)
	@./pamonha

clean:
	$(RM) *.out

fclean: clean
	$(RM) $(NAME)

re: fclean all
