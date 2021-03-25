
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
        printf("\nFin de la COMMANDE\n");
        ft_display_lst(lst_a, lst_b);
        //printf("len_a = %d et len_b = %d\n", ft_lstsize(lst_a->first), ft_lstsize(lst_b->first));

    }
    free(line);
    return (0);
}


t_data      *initialize_listb(void)
{
    t_data *lst;
    //t_list *elem;

    if (!(lst = malloc(sizeof(t_data))))
        return (NULL);
    //if (!(elem = malloc(sizeof(t_list))))
    //    return (NULL);
    //elem->next = NULL;
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

int        ft_start(int argc, char **argv)
{
    t_data      *lst_a;
    t_data      *lst_b;
    //int         len_b;

    // Cree une liste et ajoute le premier element
    lst_a = initialize_list(argc, argv);
    lst_b = initialize_listb();
    
    //(void)lst_b;
    
    //len_b = ft_free_lst_b(lst_b);
    //(void)len_b;
    
    //Ajoute tous les chiffres dans la liste A sauf le premier
    ft_full_insertion(lst_a, argc, argv);
    // affiche la liste A
    
    ft_display_lst(lst_a, lst_b);

    printf("lst_a->first->number = %d\n", lst_a->first->number);
    printf("lst_a->last->number = %d\n", lst_a->last->number);
    
    //printf("len_a = %d et len_b = %d\n", ft_lstsize(lst_a->first), ft_lstsize(lst_b->first));
    
    
    // Delete le premier element cad dessus
    //ft_delete_first(lst_a);
    // affiche la liste A
    //ft_display_lst(lst_a);
    // Supprime tous les elements de la liste
    //ft_free_all(lst_a, argc);

    if ((ft_get_cmd(lst_a, lst_b) == 1))
    {
        ft_free_all(lst_a, lst_b); 
        return (1);
    }

    ft_display_lst(lst_a, lst_b);
    ft_free_all(lst_a, lst_b);     

      
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
        ///printf("%zu\n", ft_strlen(argv[1]));
        
    }
    return (0);
}