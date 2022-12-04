/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:26:22 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/04 14:12:56 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

typedef struct s_list
{
    int				*nbr;
    struct s_list	*next;
}t_list;

void	rev_rotate(t_list **list);
void	rotate(t_list **list);
void	push(t_list **list1, t_list **list2);
void	swap(t_list **list);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int   nbr);
unsigned int	ft_atoi_base(char *str);
#endif