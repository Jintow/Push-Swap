/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:03:33 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/04 14:04:00 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_list **list)
{
    t_list  *first;
    t_list  *second;

    if (!(*list) || !(*list)->next)
        return ;
    first = *list;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *list = second;
}

void    push(t_list **list1, t_list **list2)
{
    t_list *temp;

    if (!(*list2))
        return ;
    if (!(*list1))
    {
        *list1 = *list2;
        *list2 = (*list2)->next;
        (*list1)->next = NULL;
    }
    else
    {  
        temp = (*list2)->next;
        ft_lstadd_front(list1, *list2);
        *list2 = temp;
    }
}

void    rotate(t_list **list)
{
    t_list  *second;

    if (!(*list) || !(*list)->next)
        return ;
    second = (*list)->next;
    ft_lstadd_back(list, *list);
    *list = second;
}

void    rev_rotate(t_list **list)
{
    t_list  *last;
    t_list  *temp;

    if (!(*list) || !(*list)->next)
        return ;
    temp = *list;
    while (temp->next->next)
        temp = temp->next;
    last = temp->next;
    temp->next = NULL;
    last->next = *list;
    *list = last;
}
