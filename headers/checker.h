#ifndef CHECKER_H
# define CHECKER_H



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "get_next_line.h"



typedef struct          s_list
{
    int             number;
    struct s_list          *prev; 
    struct s_list          *next;   
}                       t_list;

typedef struct s_data
{
    t_list     *first;
}               t_data;


#endif