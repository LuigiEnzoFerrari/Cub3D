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

RENDER := map_rays.c map_player.c projection.c map.c background.c
RENDER_PATH := $(addprefix render/, $(RENDER))

UPDATE := ray_minimum.c ray_vertical.c raycasting.c update_util.c \
		player.c ray_horizontal.c
UPDATE_PATH := $(addprefix update/, $(UPDATE))

SETTINGS := map_get_utils.c ele_init_val.c ele_check_rgb.c map_check_utils.c \
		ele_get_r.c ele_get_utils.c ele_clear_spaces.c temp.c \
		ele_check_res.c ele_check_tex.c ele_check_configs.c \
		map_clear_spaces.c settings.c free_exit_elements.c \
		map_check_map.c map_get.c map_clear_utils.c map_check_utils2.c \
		ele_configs.c ele_check_args.c ele_get_tex.c ele_get_fc.c
SETTINGS_PATH := $(addprefix settings/, $(SETTINGS))

INPUT := input.c
INPUT_PATH := $(addprefix input/, $(INPUT))

MLX_E := mlx_get_line.c mlx_draw_fill_rect.c mlx_get_circle.c \
		mlx_draw_circle.c mlx_set_render_color.c mlx_put_pixel.c \
		mlx_trgb_to_hex.c mlx_render_present.c mlx_get_rect.c \
		mlx_create_renderer.c mlx_draw_line.c

MLX_E_PATH := $(addprefix mlx_extension/, $(MLX_E))

INIT := set_player.c initialization.c
INIT_PATH := $(addprefix initialization/, $(INIT))

SRC_PATH := $(RENDER_PATH) $(UPDATE_PATH) $(SETTINGS_PATH) $(INPUT_PATH) $(MLX_E_PATH) $(INIT_PATH)

SRC := $(addprefix srcs/, $(SRC_PATH)) srcs/main.c

all: $(NAME)

$(NAME): $(SRC) $(LIB_SRC) $(HEADERS)
	@$(CC) $(CFLAGS) $(SANIT) $(SRC) $(LIB_LINK) $(INC) $(MLX_FLAGS) -o $@

$(LIB_SRC):
	@make -C libs/libft
	@make -C libs/Libft2D
	@make -C libs/libx

install:
	@sudo apt-get install gcc make xorg libxext-dev libbsd-dev

run: $(NAME)
	@./cub maps/game.cub

clean: 
	@$(RM) $(NAME)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libs/libft
	@make fclean -C libs/Libft2D
	@make clean -C libs/libx

re: fclean all
