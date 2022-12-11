/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:46 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/11 22:02:17 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listi	*ft_lstnew_loc(int nbr)
{
	t_listi	*new;

	new = malloc(sizeof(t_listi));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front_loc(t_listi **lst, t_listi *new)
{
	if (!lst)
	{
		if (new)
			lst = &new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_loc(t_listi **lst, t_listi *new)
{
	t_listi	*p_lst;

	if (!lst)
	{
		if (new)
			lst = &new;
		return ;
	}
	if (!(*lst))
	{
		if (new)
			*lst = new;
		return ;
	}
	if (new)
	{
		p_lst = *lst;
		while (p_lst->next)
			p_lst = p_lst->next;
		p_lst->next = new;
		new->next = NULL;
	}
}

size_t	lst_size_loc(t_listi *lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_listi	*ft_lstlast_loc(t_listi *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

size_t	ft_lstsize_loc(t_listi *lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
