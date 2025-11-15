# Makefile — 最小可用且合规
NAME    = fractol
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
# 按你的机器实际路径修改 MLX 库与头文件位置
MLX_INC = -I/usr/include
MLX_LIB = -lmlx -lXext -lX11 -lm   # Linux 常见组合；macOS 可用 -lmlx -framework OpenGL -framework AppKit

SRC     = fractol.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_INC) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
