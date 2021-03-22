
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

int     main(int argc, char **argv)
{
    int ret;

    char *line;
    int ret_gnl;
    ret_gnl = 0;
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
        ret_gnl = get_next_line(0, &line);
        printf("FIRST LIGNE = %s\n", line);
        while (ret_gnl != 0)
        {
            printf("line = -%s-\n", line);
            free(line);
            ret_gnl = get_next_line(0, &line);
        }
        free(line);
        //line= NULL;
    }
    //free(line);
    return (0);
}