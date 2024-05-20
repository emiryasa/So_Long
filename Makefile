NAME = so_long
SRCS = map.c
OBJS = ${SRCS:.c=.o}
G_FLAGS = -Wall -Werror -Wextra
LIBFTDIR = libft
LIBFT = ./${LIBFTDIR}/libft.a

all: $(NAME)

$(NAME) : $(LIBFTDIR) $(OBJS)
	make -C $(LIBFTDIR) 
	gcc $(G_FLAGS) $(NAME).c $(OBJS) ${LIBFT} -o $(NAME)

clean: $(LIBFTDIR)
	make clean -C $(LIBFTDIR)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all