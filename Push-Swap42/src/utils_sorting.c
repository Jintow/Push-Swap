/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:27:03 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/12 16:04:20 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sorting(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	if (no_more_low_piv(*lb, piv, low_piv))
		return ;
	check_andput_nb(lb, piv, low_piv, 1);
	check_andput_nb(lb, piv, low_piv, 0);
	temp = *lb;
	if (temp && temp->pos == 0 && temp->low_piv == low_piv)
	{
		if ((*la)->nbr > (*la)->next->nbr)
			swap(la, 'a');
		push(la, lb, 'a');
		(*la)->low_piv -= 20;
		init_sorting(la, lb, piv, low_piv);
	}
	else if (temp && temp->next && temp->next->pos == 0 && \
		temp->next->low_piv == low_piv)
	{
		if ((*la)->nbr > (*la)->next->nbr)
			double_swap(la, lb);
		else
			swap(lb, 'b');
		push(la, lb, 'a');
		(*la)->low_piv -= 20;
		init_sorting(la, lb, piv, low_piv);
	}
	else if (temp && temp->next && temp->next->next && \
		temp->next->next->pos == 0 && temp->nb_elem_categ <= 3 && \
			temp->next->next->low_piv == low_piv)
	{
		sort_three_lb(la, lb, piv, low_piv);
		init_sorting(la, lb, piv, low_piv);
	}
}

int	count_elem(t_listi	**lst, int piv, int low_piv)
{
	t_listi	*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	temp = *lst;
	while (temp && temp->piv == piv && temp->low_piv >= low_piv - 1 && temp->low_piv <= low_piv + 1)
	{
		if (temp->low_piv == low_piv - 1)
			i++;
		else if (temp->low_piv == low_piv)
			j++;
		else
			k++;
		temp = temp->next;
	}
	temp = *lst;
	while (temp && temp->piv == piv && temp->low_piv >= low_piv - 1 && temp->low_piv <= low_piv + 1)
	{
		if (temp->low_piv == low_piv - 1)
			temp->nb_elem_categ = i;
		else if (temp->low_piv == low_piv)
			temp->nb_elem_categ = j;
		else
			temp->nb_elem_categ = k;
		temp = temp->next;
	}
	return (j);
}

void	check_andput_nb(t_listi **lst, int piv, int low_piv, int nb)
{
	t_listi	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->low_piv == low_piv && temp->piv == piv && temp->pos == nb)
			return ;
		temp = temp->next;
	}
	temp = *lst;
	while (temp)
	{
		if (temp->low_piv == low_piv && temp->piv == piv && temp->pos > nb)
			temp->pos -= 1;
		temp = temp->next;
	}
}

// void	check_andput_nb(t_listi **lst, int piv, int low_piv, int nb)
// {
// 	t_listi	*temp;

// 	temp = *lst;
// 	while (temp && temp->low_piv == low_piv && temp->piv == piv)
// 	{
// 		if (temp->pos == nb)
// 			return ;
// 		temp = temp->next;
// 	}
// 	temp = *lst;
// 	while (temp && temp->low_piv == low_piv && temp->piv == piv)
// 	{
// 		if (temp->pos > nb)
// 			temp->pos -= 1;
// 		temp = temp->next;
// 	}
// }

int	no_more_piv(t_listi	*lst, int piv)
{
	while (lst)
	{
		if (lst->piv == piv)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	no_more_low_piv(t_listi	*lst, int piv, int low_piv)
{
	while (lst && lst->piv == piv)
	{
		if (lst->low_piv == low_piv)
			return (0);
		lst = lst->next;
	}
	return (1);
}
