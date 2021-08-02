NAME	= libarray.a
CC		= clang
CFLAGS	= -Wall -Wextra -Werror

INC_PATH := include ../libft
INC		:= $(addprefix -I , $(INC_PATH))

DIRS	:= string put
SRC		:= $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBS		:= $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBS)
	ar -rcs $(NAME) $(OBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	$(RM) $(OBS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
