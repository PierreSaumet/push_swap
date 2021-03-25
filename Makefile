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

SRCS		+=		srcs/free/free_list.c		\
					srcs/lists/lst_init_insert.c	\
					srcs/lists/lst_display.c		\
					srcs/cmd/ft_check_cmd.c			\
					srcs/cmd/ft_push.c				\
					srcs/cmd/ft_reverse_rotate.c	\
					srcs/cmd/ft_rotate.c			\
					srcs/cmd/ft_swap.c				

LIBFT		=		libraries/libft/libft.a

GNL			=		libraries/gnl/get_next_line.a

HEADER		+=		headers/checker.h \
					libraries/libft/libft.h	\
					libraries/gnl/get_next_line.h

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

OBJS		=		$(SRCS:.c=.o)

INCLUDES	=		headers/


all: libftcomp gnlcomp $(NAME)

$(OBJS): %.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@ -g

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -lm -o $@

libftcomp:
		cd libraries/libft && make

gnlcomp:
		cd libraries/gnl && make
clean:
		@rm -rf *.o
		@rm -rf  libraries/gnl/*.o 
		@rm -rf  libraries/libft/*.o
		@rm -rf srcs/cmd/*.o
		@rm -rf srcs/lists/*.o
		@rm -rf srcs/free/*.o
fclean:	clean
				@rm -rf $(NAME)
				@rm -rf libraries/libft/*.a
				@rm -rf libraries/gnl/*.a


.SILENT:%