NAME 		= 	get_next_line.a
SRCS 		=	get_next_line.c
				
LIBFT		=	../libft/libft.a
HEADER		+=	get_next_line.h
OBJS		=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) -c $(SRCS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
	/bin/rm -f *.o
fclean:		clean
	/bin/rm -f  $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
