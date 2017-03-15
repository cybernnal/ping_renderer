//
// Created by tom billard on 15/03/2017.
//

#include <ping.h>

static t_list *get_new(void)
{
    t_list *lst;
    t_list *first;
    int i = 0;
    lst = (t_list*)ft_memalloc(sizeof(t_list));
    first = lst;
    while (i < MAX - 1)
    {
        lst->next = (t_list*)ft_memalloc(sizeof(t_list));
        bzero(lst->next, sizeof(t_list));
        lst = lst->next;
        i++;
    }
    return (first);
}

float process_list(t_list **lst, t_list **first, float t)
{
    static int nb = 0;
    static float max = 0;

    if (nb == 0)
    {
        *lst = get_new();
        *first = *lst;
    }
    else if (nb < MAX)
    {
        *lst = (*lst)->next;
    }
    else
    {
        (*lst)->next = *first;
        *first = (*first)->next;
        *lst = (*lst)->next;
        (*lst)->next = NULL;
        if ((*lst)->t == max)
            max = get_max(first);
    }
    (*lst)->t = t;
    if (t > max)
        max = t;
    nb++;
    return (max);
}