/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:27:03 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/11 18:06:30 by Teiki            ###   ########.fr       */
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
	if (temp && temp->pos == 0)
	{
		push(la, lb, 'a');
		(*la)->low_piv -= 20;
		init_sorting(la, lb, piv, low_piv);
	}
	else if (temp && temp->next && temp->next->pos == 0)
	{
		swap(lb, 'b');
		push(la, lb, 'a');
		(*la)->low_piv -= 20;
		init_sorting(la, lb, piv, low_piv);
	}
	else if (temp && temp->next && temp->next->next && temp->next->next->pos == 0 && temp->nb_elem_categ <= 3)
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
	while (temp && temp->low_piv == low_piv && temp->piv == piv)
	{
		if (temp->pos == nb)
			return ;
		temp = temp->next;
	}
	temp = *lst;
	while (temp && temp->low_piv == low_piv && temp->piv == piv)
	{
		if (temp->pos > nb)
			temp->pos -= 1;
		temp = temp->next;
	}
}

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
