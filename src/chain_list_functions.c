/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:46 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/04 14:13:52 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nbr)
{
    t_list	*new;

    new = malloc(sizeof(t_list *));
    new->nbr = malloc(sizeof(int));
    new->nbr[0] = nbr;
    new->next = NULL;
    return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!new)
        return;
    if (!lst || !(*lst))
    {
        *lst = new;
        return;
    }
    new->next = *lst;
    *lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list	*temp;
    
    if (!new)
        return;
    if (!lst || !(*lst))
    {
        *lst = new;
        return;
    }
    temp = *lst;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    new->next = NULL;
}

