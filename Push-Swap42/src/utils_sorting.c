/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:27:03 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/09 17:08:51 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sorting(t_listi **lst_from, t_listi **lst_to, int low_piv)
{
	t_listi	*temp;

	check_andput_one(lst_from, low_piv);
	check_andput_zero(lst_from, low_piv);
	temp = *lst_from;
	if (temp && temp->pos == 0)
	{
		push(lst_to, lst_from, 'a');
		check_andput_zero(lst_from, low_piv);
		init_sorting(lst_from, lst_to, low_piv);
	}
	else if (temp && temp->next && temp->next->pos == 0)
	{
		swap(lst_from, 'b');
		push(lst_to, lst_from, 'a');
		check_andput_zero(lst_from, low_piv);
		init_sorting(lst_from, lst_to, low_piv);
	}
	else if (temp && temp->next && temp->next->next && temp->next->next->pos == 0 \
		&& (temp->pos == 1 || temp->next->pos == 1))
		sort_three_lb(lst_to, lst_from);
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

void	check_andput_zero(t_listi **lst, int low_piv)
{
	t_listi	*temp;

	temp = *lst;
	while (temp && temp->low_piv == low_piv)
	{
		if (temp->pos == 0)
			return ;
		temp = temp->next;
	}
	temp = *lst;
	while (temp && temp->low_piv == low_piv)
	{
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

void	check_andput_one(t_listi **lst, int low_piv)
{
	t_listi	*temp;

	temp = *lst;
	while (temp && temp->low_piv == low_piv)
	{
		if (temp->pos == 1)
			return ;
		temp = temp->next;
	}
	temp = *lst;
	while (temp && temp->low_piv == low_piv)
	{
		if (temp->pos != 0)
			temp->pos -= 1;
		temp = temp->next;
	}
}



