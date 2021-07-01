CC := clang
CFLAGS := -Wall -Werror -Wextra
SANIT := -g -fsanitize=address

SRC_PATH := gnl
SRC := main.c ../Libft2D/libft2d.a $(wildcard $(addprefix ../, $(SRC_PATH))/*.c)
INC_PATH := libft gnl libft2D
INC := $(addprefix -I , $(addprefix ../, $(INC_PATH)))
LIB_PATH := libft libft2D
LIB := $(addprefix -L, $(addprefix ../, $(LIB_PATH)))


all:
	$(CC) $(CFLAGS) $(SANIT) $(SRC) $(LIB) -lft $(INC)