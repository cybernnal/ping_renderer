//
// Created by tom billard on 15/03/2017.
//

#include <ping.h>
void print_lst(t_list *lst)
{
    while (lst)
    {
        printf("%f ", lst->t);
        lst = lst->next;
    }
    printf("\n");
}
