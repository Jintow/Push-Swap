/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:55:36 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/10 19:48:54 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_categ_sorting(t_listi **lst, int piv, int low_piv, int max);
void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv);
void	pivot_right(t_listi **la, t_listi **lb, int piv, int low_piv);
void	split_low_piv(t_listi *lst);
void	check_and_pull_back(t_listi **la, t_listi **lb, int piv, int low_piv);
void	check_and_pull_back_b(t_listi **lb, int piv, int low_piv);
void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv);

void	left_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;

	if (*lb == NULL)
	{
		ft_printf("\n");
		print_listi(*la, *lb);
		exit(0);
	}
	//ft_printf("\nLeft Sorting, piv : %d, low_piv : %d\n", i_piv, low_piv);
	if (i_piv != 5 || low_piv != 1)
		check_and_pull_back_b(lb, i_piv, low_piv);
	init_sorting(lb, la, i_piv, low_piv);
	count = count_elem(lb, i_piv, low_piv);
	if (low_piv > 1)
		left_sorting(la, lb, i_piv + 1, 0);
	// if (i_piv == 5 && low_piv == -3)
	// {
	// 	ft_printf("\nPivot Sorting, nb_elem_categ ; %d, low_piv :%d\n", (*lb)->nb_elem_categ, low_piv);
	// 	print_listi(*la, *lb);
	// 	exit (0);
	// }
	else if (count == 0)
	{
		if (ft_lstlast_loc(*la)->low_piv == low_piv + 1 && ft_lstlast_loc(*la)->piv == i_piv)
			right_sorting(la, lb, i_piv, low_piv);
		else
			left_sorting(la, lb, i_piv, low_piv + 1);
	}
	else
	{
		split_categ_sorting(lb, i_piv, low_piv, count_elem(lb, i_piv, low_piv));
		count_elem(lb, i_piv, low_piv);
		// ft_printf("\nLeft Sorting, piv : %d, low_piv : %d, nb_elem_categ ; %d\n", i_piv, low_piv, (*lb)->nb_elem_categ);
		pivot_left(la, lb, i_piv, low_piv - 1);
		// if ((*lb)->nbr < 803)
		// {
		// 	ft_printf("\nLeft Sorting, piv : %d, low_piv : %d, nb_elem_categ ; %d\n", i_piv, low_piv, (*lb)->nb_elem_categ);
		// 	print_listi(*la, *lb);
		// 	exit(0);
		// }
		right_sorting(la, lb, i_piv, low_piv - 2);
	}
}

void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;
	static	int i;

	i++;
	// if (i_piv == 5 && low_piv == -3)
	// {
	// 	ft_printf("\nPivot Sorting, nb_elem_categ ; %d, low_piv :%d\n", (*lb)->nb_elem_categ, low_piv);
	// 	print_listi(*la, *lb);
	// 	exit (0);
	// }
	//ft_printf("\n\n");
	init_sorting_la(la, lb, i_piv, low_piv);
	count = count_elem(la, i_piv, low_piv);
	//ft_printf("\nRight Sorting, piv : %d, low_piv : %d, nb_elem_categ ; %d, count : %d\n", i_piv, low_piv, (*la)->nb_elem_categ, count);
	if (count == 0 && ft_lstlast_loc(*la)->low_piv == low_piv + 1 && ft_lstlast_loc(*la)->piv == i_piv)
	{
		check_and_pull_back(la, lb, i_piv, low_piv + 1);
		right_sorting(la, lb, i_piv, low_piv + 1);
	}
	else if (count == 0)
		left_sorting(la, lb, i_piv, low_piv);
	else
	{
		split_categ_sorting(la, i_piv, low_piv, count);
		pivot_right(la, lb, i_piv, low_piv - 1); //+possibilites de double rev_rot, a priori non!
		left_sorting(la, lb, i_piv, low_piv - 2); // attention aux conditions particulieres dans la;
		// print_listi(*la, *lb);
		// exit(0);
	}
}

void	split_categ_sorting(t_listi **lst, int piv, int low_piv, int max)
{
	t_listi	*temp;

	temp = *lst;
	while (temp && temp->low_piv == low_piv)
	{
		if (temp->pos < max / 2)
			temp->low_piv -= 1;
		else
			temp->pos -= max / 2;
		temp = temp->next;
	}
}

void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*lb) && (*lb)->low_piv <= low_piv + 1 && (*lb)->piv == piv)
	{
		if ((*lb)->low_piv == low_piv + 1)
		{
			if ((*la)->low_piv == low_piv) // surveiller le ">= dans des cas particuliers" + eventuellement eviter rr+ rrr si c'est le dernier
				double_rotate(la, lb);
			else if (no_more_low_piv(*lb, piv, low_piv))
				break ;
			else
				rotate(lb, 'b');
			if ((*la)->nbr > (*la)->next->nbr)
			{
				if ((*lb)->nbr < (*lb)->next->nbr)
					double_swap(la, lb);
				else if ((*la)->nb_elem_categ <= 8)
					swap(la, 'a');
			}
		}
		else
		{
			split_low_piv(*lb);
			if ((*la)->low_piv == low_piv && (*lb)->low_piv == low_piv - 1)
			{
				while ((*la)->low_piv == low_piv)
					rotate(la, 'a');
			}
			push(la, lb, 'a');
			if ((*la)->nbr > (*la)->next->nbr)
			{
				if ((*lb)->nbr < (*lb)->next->nbr)
					double_swap(la, lb);
				else if ((*la)->nb_elem_categ <= 8)
					swap(la, 'a');
			}
		}
	}
	while ((*la)->low_piv == low_piv)
		rotate(la, 'a');
}

void	split_low_piv(t_listi *lst)
{
	if (lst->nb_elem_categ <= 3)
		return ;
	if (lst->pos > lst->nb_elem_categ / 2 - (1 - (lst->nb_elem_categ % 2)))
		lst->pos -= lst->nb_elem_categ / 2;
	else
		lst->low_piv -= 1;
}

void	check_and_pull_back(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	t_listi	*temp;

	while (ft_lstlast_loc(*la)->low_piv == low_piv && \
		ft_lstlast_loc(*la)->piv == piv)
	{
		temp = ft_lstlast_loc(*lb);
		if (temp->low_piv == low_piv + 1 && temp->piv == piv)
			double_rev_rotate(la, lb);
		else
			rev_rotate(la, 'a');
		if ((*la)->nbr > (*la)->next->nbr)
		{
			if ((*lb)->nbr < (*lb)->next->nbr)
				double_swap(la, lb);
			else if ((*la)->nb_elem_categ <= 8)
				swap(la, 'a');
		}
	}
}

void	check_and_pull_back_b(t_listi **lb, int piv, int low_piv)
{
	while (ft_lstlast_loc(*lb)->low_piv == low_piv && \
		ft_lstlast_loc(*lb)->piv == piv)
	{
		rev_rotate(lb, 'b');
		if ((*lb)->nbr < (*lb)->next->nbr && (*lb)->nb_elem_categ <= 5)
			swap(lb, 'b');
	}
}

void	pivot_right(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*la)->low_piv <= low_piv + 1 && (*la)->piv == piv)
	{
		if ((*la)->low_piv == low_piv + 1)
			rotate(la, 'a');
		else
			push(lb, la, 'b');
	}
}
