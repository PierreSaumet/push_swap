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

    int         nbr;
    int         total;
    int         median;
    int         q_one;
    int         q_three;
    int         count_ra;
}               t_data;


/*
**  File lst_display.c 
*/
int         ft_display_lst(t_data *listA, t_data *listB);

/*
**  File lst_init_insert.c
*/
int        ft_insertion(t_data *lst_a, int nbr);
int         ft_full_insertion(t_data *lst_a, int nbr, char **argv);
t_data      *initialize_list(int argc, char **argv);
t_data      *initialize_listb(void);

/*
**  File free_list.c
*/
void    ft_free_tab(char **tab, int nbr);
int	ft_lstsize(t_list *lst);
int        ft_delete_first(t_data *lst_a);
int    ft_free_all(t_data *lst_a, t_data *lst_b);


/*
**  File ft_check_cmd.c
*/
int     ft_check_cmd(char *line, t_data *lst_a, t_data *lst_b);
int         ft_rr(t_data *lst_a, t_data *lst_b);
int         ft_ss(t_data *lst_a, t_data *lst_b);
int         ft_rrr(t_data *lst_a, t_data *lst_b);
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

/*
**  File ft_check_args.c
*/
int     ft_check_args(int argc, char **argv, int i);
int    ft_count(int argc, char **argv);

/*
**  File ft_get_nbr.c
*/
char    **ft_malloc_tab(int nbr, int argc, char **argv);
char    **ft_get_nbr(int argc, char **argv, char **tab, int nbr);




/*
**  File push_swap.c
*/
int         ft_end(t_data *lst_a, t_data *lst_b);

/*
**  File sort_three.c
*/
int         nbr_three(int nbr, t_data *lst_a, t_data *lst_b);
int         ft_find_big(t_data *lst);
int         ft_find_small(t_data *lst);
int         solve_3(t_data *lst_a);
/*
**  File sort_ten.c
*/
int         nbr_ten(int nbr, t_data *lst_a, t_data *lst_b);


int			find_mediane(int nbr, t_data *lst_a);
int			other(int nbr, t_data *lst_a, t_data *lst_b);
int         ft_ordre_croissant(t_data *lst_a, t_data *lst_b);


/*
**  File sort_middle.c.c
*/
int             test(int nbr, t_data *lst, t_data *lst_b);

int         ft_len_list(t_data *lst);
int             ft_do_pb(t_data *lst_a, t_data *lst_b);
int             ft_do_rb(t_data *lst);
int             ft_do_ra(t_data *lst_a);
int             ft_do_rra(t_data *lst_a);
int             ft_do_rrb(t_data *lst);
int         sort_2000(int nbr, t_data *lst_a, t_data *lst_b);
int				ft_find_best(int nbr, t_data *lst, int div);

#endif