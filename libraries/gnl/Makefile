# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/08/15 11:05:30 by psaumet           #+#    #+#             #
#   Updated: 2020/08/15 18:14:06 by psaumet          ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME 		= 	get_next_line.a

################################### SOURCES ##################################

SRCS 		+=	get_next_line.c	\
				get_next_line_utils.c

################################### HEADERS ##################################

HEADER		+=	get_next_line.h

################################# VARIABLES ##################################

LIBFT		=	../libft/libft.a
OBJS		=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror

################################### RULES ####################################

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
