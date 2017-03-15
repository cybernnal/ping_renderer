//
// Created by tom billard on 15/03/2017.
//

#include <ping.h>

float get_max(t_list **l)
{
    float m = 0;
    t_list  *lst = *l;

    while (lst->next)
    {
        if (m < lst->t)
            m = lst->t;
        lst = lst->next;
    }
    return (m);
}

void print_lst(t_list *lst)
{
    while (lst)
    {
        printf("%f ", lst->t);
        lst = lst->next;
    }
    printf("\n");
}
