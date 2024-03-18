NAME = so_long.a


SRCS =	$(wildcard sources/*.c) \
		$(wildcard get_next_line/*.c) \
		$(wildcard sources/utils/*.c) \
		$(wildcard sources/utils/side_walks_functions/*.c)


OBJS =  $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf


### Rules #############################################

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	$(CC) -g main.c $(CFLAGS) $(SRCS) -L minilibx-linux -lmlx_Linux -o so_long -lX11 -lXext


all: $(NAME)


clean:
	@ $(RM) $(OBJS)


fclean: clean
	@ $(RM) $(NAME)
	@ $(RM)	so_long
	@ $(RM) minilibx-linux


re: fclean all


minilibx:
	wget https://cdn.intra.42.fr/document/document/22065/minilibx-linux.tgz
	tar -xvzf minilibx-linux.tgz
	$(RM) minilibx-linux.tgz
	$(MAKE) -C minilibx-linux


.PHONY: all clean fclean re