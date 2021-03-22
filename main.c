
#include "headers/checker.h"


int     ft_check_args(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    else
    {
        argc--;
        while (argc > 0)
        {
            while (argv[argc][i])
            {
                if (isdigit(argv[argc][i]) == 0)
                {
                    if (argv[argc][i] == '-' && isdigit(argv[argc][i + 1]))
                        i++;
                    else
                        return (1);
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

t_data      *initialize_list(int argc, char **argv)
{
    t_data *list;
    t_list  *element;

    if (!(list = malloc(sizeof(t_data))))
        return (NULL);
    if (!(element = malloc(sizeof(t_list))))
        return (NULL);
    element->number = atoi(argv[argc - 1]);
    element->next = NULL;
    list->first = element;

    return (list);
}

void        ft_insertion(t_data *listA, int nbr)
{
    t_list *new;

    if (!(new = malloc(sizeof(t_list))))
        return ;
    new->number = nbr;
    new->next = listA->first;
    listA->first = new;
}

int         ft_print(t_data *listA)
{
    if (listA == NULL)
        return (1);
    t_list *elem = listA->first;

    while (elem != NULL)
    {
        printf("%d\n", elem->number);
        elem = elem->next;
    }
    printf("_\na\n");
    return (0);
}

int        ft_delete_first(t_data *listA)
{
    t_list *to_del;
    if (listA == NULL)
        exit (EXIT_FAILURE);
    if (listA->first != NULL)
    {
        to_del = listA->first;
        listA->first = listA->first->next;
        free(to_del);
    }
    return (0);
}

int         ft_full_insertion(t_data *listA, int argc, char **argv)
{
    argc = argc - 1;
    while (argc > 1)
    {
        t_list *new;

        if (!(new = malloc(sizeof(t_list))))
            return 1;
        new->number = atoi(argv[argc - 1]);
        new->next = listA->first;
        listA->first = new;
        argc--;
    }
    return (0);
}


int    ft_free_all(t_data *listeA, int argc)
{
    while ((argc - 1) > 0)
    {
        ft_delete_first(listeA);
        argc--;
    }
    free(listeA);
    return (0);
}

void        ft_start(int argc, char **argv)
{
    t_data      *listeA;

    listeA = initialize_list(argc, argv);
    ///ft_insertion(listeA, 9);
    //ft_insertion(listeA, 4);
    ft_full_insertion(listeA, argc, argv);
    ft_print(listeA);


    printf("\n\n on supprime 1 element\n");
    ft_delete_first(listeA);
    ft_print(listeA);

    ft_free_all(listeA, argc);
    //free(listeA);
    
}

// ! Changer strcmp en ft_strcmp
int     ft_check_cmd(char *line)
{
    if (strcmp(line, "sa") == 0)
    {
        // ft_sa
        printf("cas SA\n");
    }
    else if (strcmp(line, "sb") == 0)
    {
        // ft_sb
        printf("cas SB\n");
    }
    else if (strcmp(line, "ss") == 0)
    {
        // ft_ss
        printf("cas SS\n");
    }
    else if (strcmp(line, "pa") == 0)
    {
        // ft_pa
        printf("cas PA\n");
    }
    else if (strcmp(line, "pb") == 0)
    {
        // ft_pb
        printf("cas PB\n");
    }
    else if (strcmp(line, "ra") == 0)
    {
        // ft_ra
        printf("cas RA\n");
    }
    else if (strcmp(line, "rb") == 0)
    {
        // ft_rb
        printf("cas RB\n");
    }
    else if (strcmp(line, "rr") == 0)
    {
        // ft_rr
        printf("cas RR\n");
    }
    else if (strcmp(line, "rra") == 0)
    {
        // ft_rra
        printf("cas RRA\n");
    }
    else if (strcmp(line, "rrb") == 0)
    {
        // ft_rrb
        printf("cas RRB\n");
    }
    else if (strcmp(line, "rrr") == 0)
    {
        /// ft_rrr
        printf("cas RRR\n");
    }
    else
    {
        printf("ERREUR CMD\n");
        return (1);
    }
    free(line);
    return (0);
}

int     ft_get_cmd(void)
{
    int ret_gnl;
    char    *line;
    int     ret;

    ret = 0;
    printf("\n\nDEBUT GNL\n");
    ret_gnl = get_next_line(0, &line);
    printf("premier gnl... ret_gnl = %d \t et line = -%s-\n", ret_gnl, line);
    while (ret_gnl != 0)
    {
        printf("debut boucle\n");
        ret = ft_check_cmd(line);
        if (ret != 1)
        {
            //printf("line = -%s- et le retour de ft_check_cmd = %d\n", line, ret);
            //free(line);
            ret_gnl = get_next_line(0, &line);
        }
        else
            break;
        printf("fin de boucle\n");
    }
    printf("on sort\n");
    free(line);
    return (0);
}

int     main(int argc, char **argv)
{
    int ret;

    printf("argc = %d and argv[0] = %s and argv[1] = %s\n", argc, argv[0], argv[1]);
    ret = ft_check_args(argc, argv);
    if (ret == 1)
    {
        write(1, "Error 3\n", 8);
        return (1);
    }
    else
    {
        write(1, "OK\n", 3);
        ft_start(argc, argv);

        if ((ft_get_cmd() == 1))
            exit(EXIT_FAILURE);
        //ft_get_cmd();
        // get the commands
        /*
        ret_gnl = get_next_line(0, &line);
        printf("FIRST LIGNE = %s\n", line);
        while (ret_gnl != 0)
        {
            printf("line = -%s-\n", line);
            free(line);
            ret_gnl = get_next_line(0, &line);
        }
        free(line);*/
        //line= NULL;
    }
    //free(line);
    return (0);
}