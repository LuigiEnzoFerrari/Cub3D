NAME := cub
CC := clang
SANIT := -g -fsanitize=address
CFLAGS := -Wall -Wextra -Werror
MLX_FLAGS := -lm -lbsd -lXext -lX11

LIB_SRC := libs/libft/libft.a libs/Libft2D/libarray.a libs/libx/libmlx.a
LIB_DIRS := libft Libft2D libx
LIB_PATH = $(addprefix libs/, $(LIB_DIRS))
LIB_LINK := $(addprefix -L , $(LIB_PATH)) -larray -lft -lmlx

INC_PATH := $(LIB_PATH) include
INC := $(addprefix -I , $(INC_PATH))
HEADERS := $(foreach dir, $(INC_PATH), $(wildcard $(dir)/*.h))

SRC_DIR := settings initialization mlx_extension render input update
SRC_PATH := $(addprefix srcs/, $(SRC_DIR)) srcs
SRC := $(foreach dir, $(SRC_PATH), $(wildcard $(dir)/*.c))

all: $(NAME)

$(NAME): $(SRC) $(LIB_SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SANIT) $(SRC) $(LIB_LINK) $(INC) $(MLX_FLAGS) -o $@

$(LIB_SRC):
	@make -C libs/libft
	@make -C libs/Libft2D
	@make -C libs/libx

run: $(NAME)
	@./cub maps/game.cub

clean:
	$(RM) cub

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libs/libft
	@make fclean -C libs/Libft2D
	@make clean -C libs/libx

re: fclean all
