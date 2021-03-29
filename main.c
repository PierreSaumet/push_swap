
#include "headers/checker.h"


void        ft_error(void)
{
    write(1, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int     ft_check_args(int argc, char **argv, int i)
{
    if (argc < 2)   //cas 0 argument
        return (1);
    else
    {
        argc--;
        while (argc > 0)
        {
            while (argv[argc][i])
            {
                if (ft_isdigit(argv[argc][i]) == 0)
                {
                    if (((argv[argc][i] == '-' || argv[argc][i] == '+')
                            && ft_isdigit(argv[argc][i + 1])) || argv[argc][i] == ' ')
                        i++;
                    else
                        ft_error();
                }
                else
                    i++;
            }
            argc--;
            i = 0;
        }
        return (0);
    }
}



int     ft_get_cmd(t_data *lst_a, t_data *lst_b)
{
    char    *line;
 
    line = NULL;
    printf("\n\nDEBUT GNL\n");
    while ((get_next_line(0, &line) == 1))
    {
        if (ft_check_cmd(line, lst_a, lst_b) == 0)
            free(line);
        else
        {
            free(line);
            return (1);
        }
        ft_display_lst(lst_a, lst_b);
    }
    free(line);
    return (0);
}


t_data      *initialize_listb(void)
{
    t_data *lst;

    if (!(lst = malloc(sizeof(t_data))))
        return (NULL);
    lst->first = NULL;
    lst->last = NULL;
    return (lst);
}

int        ft_free_lst_b(t_data *lst_b)
{
    t_list *elem;
    int     i;

    i = 0;
    if (lst_b == NULL)
        exit (EXIT_FAILURE);
    elem = lst_b->first;
    while (elem->next != NULL)
    {
        i++;
        elem = elem->next;
    }
    printf("lst_b = %d\n", i);
    return (i);
}

int        ft_start(int nbr, char **argv)
{
    t_data      *lst_a;
    t_data      *lst_b;

    lst_a = initialize_list(nbr, argv);
    lst_b = initialize_listb();
    ft_full_insertion(lst_a, nbr - 1, argv);
    ft_display_lst(lst_a, lst_b);
    if ((ft_get_cmd(lst_a, lst_b) == 1))
    {
        ft_free_all(lst_a, lst_b); 
        return (1);
    }
    ft_display_lst(lst_a, lst_b);
    ft_free_all(lst_a, lst_b);     
    return (0);            
}

int    ft_count(int argc, char **argv)  // compte le nombre de chiffre
{
    printf("dans count\n");
    //char **tab;
    int i;
    i = 0;
    argc = argc - 1;

    int count_digit = 0;
    while (argc > 0)
    {
        printf("ARGV[%d] = -%s-\n", argc, argv[argc]);
        i = 0;
        while (argv[argc][i])
        {
            if ((argv[argc][i] == '-' || argv[argc][i] == '+') && ft_isdigit(argv[argc][i + 1]) == 1)
                i++;
            else if (ft_isdigit(argv[argc][i]) == 1)
            {
                if (argv[argc][i + 1] == ' ' || argv[argc][i + 1] == '\0')
                    count_digit++;
                i++;
            }
            else
                i++;
        }
        argc--;
    }
    printf("count_digit = %d\n", count_digit);
    // SI COUNT DIGIT = 0 pas de chiffre donc stop le programme
    return (count_digit);
}


unsigned int ft_get_len(int argc, char **argv)  // longueur max des arguments
{
    unsigned int len;
    int i;

    i = 1;
    len = strlen(argv[i]);
    
    while (i < argc)
    {
        if (len < strlen(argv[i]))
            len = strlen(argv[i]);
        i++;
    }
    printf("\n LA LONGUEUR MAX = %d\n", len);
    return (len);
}

char    **ft_malloc_tab(int nbr, int argc, char **argv)
{
    char    **tab;
    int     len;
    int     i;

    len = 0;
    i = 0;
    if (!(tab = (char **)malloc(sizeof(char *) * (nbr + 1))))
        exit(EXIT_FAILURE);
    len = ft_get_len(argc, argv);
    while (i < nbr)                 // malloc notre tablea
    {
        if (!(tab[i] = malloc(sizeof(char *) * len)))
            exit(EXIT_FAILURE);
        i++;
    }
    printf("ici\n");
    return (tab);
}


char    **ft_get_nbr(int argc, char **argv, char **tab, int nbr)
{
    int i;
    
    i = 0;
    while (argc > 0)        // on debute du dernier argument
    {
        i = strlen(argv[argc]);         // la longueur de l'arguement
        while (i >= 0)           // on parcourt l'argument
        {
            if (argv[argc][i] == '\0')          // si nfin de chaine
                i--;
            else if (ft_isdigit(argv[argc][i]))      //si c'est un chiffre
            {
                if (argv[argc][i - 1] == ' ' || argv[argc][i - 1] == '-'
                        || argv[argc][i - 1] == '+' || i == 0)        // si -1 = + ou - ou ' '
                {
                    if (i == 0)
                        strcpy(tab[nbr - 1], &argv[argc][i]);
                    else
                        strcpy(tab[nbr - 1], &argv[argc][i - 1]);
                    nbr--;
                }
                i--;      
            }
            else
                i--;
        }
        argc--;
    }
    return (tab);
}

void    ft_checker(int nbr, int argc, char **argv)
{
    char **tab;
    int i;
    
    i = 0;
    tab = NULL;
    tab = ft_malloc_tab(nbr, argc, argv);
    tab = ft_get_nbr(argc - 1, argv, tab, nbr);
    tab = ft_clean_tab(tab, nbr);
    tab = ft_del_space(tab, nbr);
    tab =ft_check_zero(tab, nbr, 0, 0);
    ft_check_int(tab, nbr);
    ft_duplicate(tab, nbr);
    printf("\n\n ULTIME FIN  tmp = %d et nbr = %d\n",  nbr, nbr);
    i = 0;
    while (i < nbr)
    {
        printf("tab[%d] = -%s-\n", i, tab[i]);
        i++;
    }
    ft_start(nbr, tab);
    ft_free_tab(tab, nbr);
}

int     main(int argc, char **argv)
{
    int ret;

    printf("argc = %d and argv[0] = %s and argv[1] = %s\n", argc, argv[0], argv[1]);
    ret = ft_check_args(argc, argv, 0);
    if (ret == 1)
        return (1);
    else
    {
        ret = ft_count(argc, argv);
        if (ret == 0)
            return (1);
        ft_checker(ret, argc, argv);  
    }
    return (0);
}