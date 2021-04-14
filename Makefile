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

NAME2		=		push_swap



TEST		+=		srcs/free/free_list.c		\
					srcs/lists/lst_init_insert.c	\
					srcs/lists/lst_display.c		\
					srcs/lists/lst_find_in.c		\
					srcs/cmd/ft_check_cmd.c			\
					srcs/cmd/ft_push.c				\
					srcs/cmd/ft_reverse_rotate.c	\
					srcs/cmd/ft_rotate.c			\
					srcs/cmd/ft_swap.c				\
					srcs/arg/ft_check_int.c			\
					srcs/arg/ft_check_duplicate.c	\
					srcs/arg/ft_check_zero.c		\
					srcs/arg/ft_del_space.c			\
					srcs/arg/ft_clean_tab.c			\
					srcs/sort/sort_three.c			\
					srcs/arg/ft_check_args.c		\
					srcs/arg/ft_get_nbr.c			\
					srcs/sort/sort_ten.c			\
					srcs/sort/sort_big_next.c			\
					srcs/sort/sort_middle.c			\
					srcs/sort/sort_big.c			\
					srcs/sort/ft_algorithm.c

C		=		checker.c


PW		=		push_swap.c

LIBFT		=		libraries/libft/libft.a

GNL			=		libraries/gnl/get_next_line.a

HEADER		+=		headers/push_swap.h \
					libraries/libft/libft.h	\
					libraries/gnl/get_next_line.h

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

OBJS		=		$(TEST:.c=.o) $(C:.c=.o)

OBJS2		=		$(TEST:.c=.o) $(PW:.c=.o)

INCLUDES	=		headers/


all: libftcomp gnlcomp $(NAME) $(NAME2) 

#$(OBJS): %.o: %.c $(HEADER)
#		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@ -g
		

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -lm -o $@


#$(OBJS2): %.o: %.c $(HEADER)
#		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@ -g
		

$(NAME2): $(OBJS2)
			$(CC) $(CFLAGS) $(OBJS2) $(LIBFT) $(GNL) -lm -o $@


libftcomp:
		@cd libraries/libft && make

gnlcomp:
		@cd libraries/gnl && make
clean:
		@rm -rf *.o
		@rm -rf  libraries/gnl/*.o 
		@rm -rf  libraries/libft/*.o
		@rm -rf srcs/cmd/*.o
		@rm -rf srcs/lists/*.o
		@rm -rf srcs/free/*.o
		@rm -rf srcs/arg/*.o
		@rm -rf srcs/sort/*.o
fclean:	clean
				@rm -rf $(NAME)
				@rm -rf $(NAME2)
				@rm -rf libraries/libft/*.a
				@rm -rf libraries/gnl/*.a

re:     fclean all

.SILENT:

.IGNORE: