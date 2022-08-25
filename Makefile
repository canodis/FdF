CC			= gcc
MINILIBX	= minilibx/libmlx.a
FLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
NAME		= Fdf
SRCS 		= main.c read_file.c draw.c fdf_utils.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(LFLAGS) $(FLAGS) $(OBJS) -o $(NAME) ./libft/libft.a ./minilibx/libmlx.a

$(MINILIBX):
	make -C minilibx
	@echo "MINILIBX compile edildi !"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	@make clean -C minilibx

re: fclean all
.PHONY: clean run fclean re all norm