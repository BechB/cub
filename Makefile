NAME    =   cub3d
SRCS    =   main.c \
            exec/window.c \
			exec/init.c \
			exec/utils.c \
			exec/read_map.c \
			exec/handle_img.c \
			exec/mini_map.c \
			parsing/parsing.c \
			mini_libft/ft_isalnum.c \
			mini_libft/ft_isalpha.c \
			mini_libft/ft_isdigit.c \
			mini_libft/ft_memcpy.c \
			mini_libft/ft_putchar.c \
			mini_libft/ft_split.c \
			mini_libft/ft_strchr.c \
			mini_libft/ft_strdup.c \
			mini_libft/ft_strjoin_free.c \
			mini_libft/ft_strlen.c \
			mini_libft/ft_strncmp.c \
			mini_libft/ft_strnstr.c \
			mini_libft/ft_strtrim.c \
			mini_libft/ft_substr.c \

OBJS     =   $(SRCS:.c=.o)
CC      = gcc 
MINILIBX_DIR = ./mlx/
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
CFLAGS = -Wall -Wextra  -Werror -I$(MINILIBX_DIR) -Iinclude -lm -g

${MAIN_PATH}%.o:%.c
	@${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o} -Iinclude -I./mlx/

all: $(NAME)

$(NAME): $(OBJS)
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L${MINILIBX_DIR} -lmlx_Linux -lXext -lX11 -lm -lz
	@echo "Archivage terminé [cub3d]"

clean:
	@rm -f $(OBJS)
	@echo "Suppression des .o"

fclean: clean
	@rm -f $(OBJS) $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re