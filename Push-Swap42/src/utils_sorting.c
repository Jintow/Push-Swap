/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:27:03 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/09 23:27:16 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sorting(t_listi **lst_from, t_listi **lst_to, int piv, int low_piv)
{
	t_listi	*temp;

	if (no_more_low_piv(*lst_from, piv, low_piv))
		return ;
	check_andput_nb(lst_from, low_piv, 2);
	check_andput_nb(lst_from, low_piv, 1);
	check_andput_nb(lst_from, low_piv, 0);
	temp = *lst_from;
	if (temp && temp->pos == 0)
	{
		push(lst_to, lst_from, 'a');
		check_andput_zero(lst_from, low_piv);
		init_sorting(lst_from, lst_to, piv, low_piv);
	}
	else if (temp && temp->next && temp->next->pos == 0)
	{
		swap(lst_from, 'b');
		push(lst_to, lst_from, 'a');
		check_andput_zero(lst_from, low_piv);
		init_sorting(lst_from, lst_to, piv, low_piv);
	}
	else if (temp && temp->next && temp->next->next && temp->next->next->pos == 0 \
		&& (temp->pos == 1 || temp->next->pos == 1))
	{
		sort_three_lb(lst_to, lst_from);
		init_sorting(lst_from, lst_to, piv, low_piv);
	}
}

int	count_elem(t_listi	**lst, int piv, int low_piv)
{
	t_listi	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = *lst;
	while (temp && temp->piv == piv && temp->low_piv <= low_piv)
	{
		if (temp->low_piv == low_piv - 1)
			i++;
		else
			j++;
		temp = temp->next;
	}
	temp = *lst;
	while (temp && temp->piv == piv && temp->low_piv <= low_piv)
	{
		if (temp->low_piv == low_piv - 1)
			temp->nb_elem_categ = i;
		else
			temp->nb_elem_categ = j;
		temp = temp->next;
	}
	return (i + j);
}

void	check_andput_nb(t_listi **lst, int low_piv, int nb)
{
	t_listi	*temp;

	temp = *lst;
	while (temp && temp->low_piv == low_piv)
	{
		if (temp->pos == nb)
			return ;
		temp = temp->next;
	}
	temp = *lst;
	while (temp && temp->low_piv == low_piv)
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
