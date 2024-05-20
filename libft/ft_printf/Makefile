SRCS = ft_functions.c ft_printf.c

NAME = libftprintf.a

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all