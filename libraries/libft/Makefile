NAME 		= 	libft.a
SRCS 		=	ft_memset.c	\
				ft_memdel.c	\
				ft_strcat.c	\
				ft_strchr.c	\
				ft_strcmp.c	\
				ft_strcpy.c	\
				ft_strdup.c	\
				ft_strjoin.c	\
				ft_strlen.c	\
				ft_strnew.c	\
				ft_substr.c
				


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
