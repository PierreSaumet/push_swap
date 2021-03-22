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

NAME		=		checker

SRCS		=		main.c

SRCS		+=		libraries/gnl/get_next_line.c				\
					libraries/gnl/get_next_line_utils.c

HEADER		+=		headers/checker.h							\
					headers/get_next_line.h

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

OBJS		=		$(SRCS:.c=.o)

INCLUDES	=		headers/


#all:			$(NAME)

#$(NAME):		${OBJS}
#				ar rc ${NAME} ${OBJS}
				
#.c.o:		${CC} ${CFLAGS} -I $(INCLUDES) -c $< -o ${<:.c=.o}



all:  $(NAME)

$(OBJS): %.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@ -g

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -lm -o $@




clean:
		rm -rf *.o && rm -rf libraries/gnl/*.o

fclean:	clean
				@rm -rf $(NAME)


.SILENT:%