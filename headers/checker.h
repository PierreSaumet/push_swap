#ifndef CHECKER_H
# define CHECKER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

#include "../libraries/libft/libft.h"
#include "../libraries/gnl/get_next_line.h"



typedef struct          s_list
{
    int             number;
    struct s_list          *prev; 
    struct s_list          *next;   
}                       t_list;

typedef struct s_data
{
    t_list      *first;
    t_list      *last;
}               t_data;


/*
**  File lst_display.c 
*/
int         ft_display_lst(t_data *listA, t_data *listB);

/*
**  File lst_init_insert.c
*/
int        ft_insertion(t_data *listA, int nbr);
int         ft_full_insertion(t_data *listA, int nbr, char **argv);
t_data      *initialize_list(int argc, char **argv);

/*
**  File free_list.c
*/
void    ft_free_tab(char **tab, int nbr);
int	ft_lstsize(t_list *lst);
int        ft_delete_first(t_data *listA);
int    ft_free_all(t_data *lst_a, t_data *lst_b);


/*
**  File ft_check_cmd.c
*/
int     ft_check_cmd(char *line, t_data *lst_a, t_data *lst_b);

/*
**  File ft_swap.c
*/
int     ft_sa(t_data *lst_a);
int     ft_sb(t_data *lst_b);

/*
**  File ft_push.c
*/
int     ft_pb(t_data *lst_a, t_data *lst_b);
int     ft_pa(t_data *lst_a, t_data *lst_b);

/*
**  File ft_rotate.c
*/
int     ft_ra(t_data *lst_a);
int     ft_rb(t_data *lst_b);

/*
**  File ft_reverse_rotate.c
*/
int     ft_rra(t_data *lst_a);
int     ft_rrb(t_data *lst_b);


/*
**  File ft_check_int.c
*/
int             ft_neg_int(char *str);
int             ft_int(char *str);
int     ft_check_int(char **tab, int argc);

/*
**  File ft_check_duplicate.c
*/
int     ft_duplicate(char **tab, int nbr);

/*
**  File ft_check_zero.c
*/
char     **ft_check_zero(char **tab, int nbr, int i, int y);


/*
**  File ft_check_zero.c
*/
char        **ft_del_space(char **tab, int argc);

/*
**  File ft_clean_tab.c
*/
char        **ft_clean_tab(char **tab, int argc);










#endif