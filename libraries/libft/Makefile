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

NAME 		= 	libft.a

################################### SOURCES ##################################

SRCS 		=	ft_atoi.c		\
				ft_isdigit.c	\
				ft_memset.c	\
				ft_memdel.c	\
				ft_split.c	\
				ft_strcat.c	\
				ft_strchr.c	\
				ft_strcmp.c	\
				ft_strcpy.c	\
				ft_strdup.c	\
				ft_strjoin.c	\
				ft_strlen.c	\
				ft_strnew.c	\
				ft_strtol.c	\
				ft_substr.c	\
				ft_strlcpy.c
				
################################# VARIABLES ##################################

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
