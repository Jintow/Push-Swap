/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:55:36 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/12 21:08:27 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv);
void	pivot_right(t_listi **la, t_listi **lb, int piv, int low_piv);
void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv);

void	left_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;

	if (*lb == NULL)
	{
		// ft_printf("\n");
		// print_listi(*la, *lb);
		exit(0);
	}
	// ft_printf("Beggining of B\n");
	init_sorting_lb(la, lb, i_piv, low_piv);
	// ft_printf("\nPULLBACK\n");
	check_and_pull_back_lb(la, lb, i_piv, low_piv);
	init_sorting_lb(la, lb, i_piv, low_piv);
	count = count_elem_in_categ(lb, i_piv, low_piv);
	if (low_piv > 1)
		left_sorting(la, lb, i_piv + 1, 0);
	else if (count == 0)
	{
		if (ft_lstlast_loc(*la)->low_piv == low_piv + 1 \
			&& ft_lstlast_loc(*la)->piv == i_piv)
			right_sorting(la, lb, i_piv, low_piv);
		else
			left_sorting(la, lb, i_piv, low_piv + 1);
	}
	else
	{
		// ft_printf("\n\nPiVOT Sorting B, piv : %d, low_piv : %d, nb_elem_categ: \
		// 	%d, count : %d, nv count :\n", i_piv, low_piv, (*lb)->nb_elem_categ, count);
		// print_listi(*la, *lb);
		split_categ_sorting(lb, i_piv, low_piv, count);
		count_elem_in_categ(lb, i_piv, low_piv - 1);
		// ft_printf("\n\nPiVOT Sorting B POST COUNTING, piv : %d, low_piv : %d, nb_elem_categ: \
			%d, count : %d, nv count :\n", i_piv, low_piv, (*lb)->nb_elem_categ, count);
		// print_listi(*la, *lb);
		pivot_left(la, lb, i_piv, low_piv - 1);
		right_sorting(la, lb, i_piv, low_piv - 2);
	}
}

void	right_sorting(t_listi **la, t_listi **lb, int i_piv, int low_piv)
{
	int	count;
	static	int i;

	i++;
	count = count_elem_in_categ(la, i_piv, low_piv);
	// ft_printf("\n\nPre init sorting A, piv : %d, low_piv : %d, nb_elem_categ: \
			%d, count : %d, nv count : %d\n", i_piv, low_piv, (*lb)->nb_elem_categ, count);
	init_sorting_la(la, lb, i_piv, low_piv);
	count = count_elem_in_categ(la, i_piv, low_piv);
	if (count == 0 && ft_lstlast_loc(*la)->low_piv == low_piv + 1 && ft_lstlast_loc(*la)->piv == i_piv)
	{
		// ft_printf("\nPULLBACK\n");
		check_and_pull_back_la(la, lb, i_piv, low_piv + 1);
		re_index_la(la, low_piv + 1);
		// print_listi(*la, *lb);
		right_sorting(la, lb, i_piv, low_piv + 1);
	}
	else if (count == 0)
		left_sorting(la, lb, i_piv, low_piv);
	else
	{
		// print_listi(*la, *lb);
		split_categ_sorting(la, i_piv, low_piv, count);
		// ft_printf("\n\nPost splitting A, piv : %d, low_piv : %d, nb_elem_categ: \
			%d, count : %d\n", i_piv, low_piv, (*la)->nb_elem_categ);
		count_elem_in_categ(la, i_piv, low_piv - 1);
		// print_listi(*la, *lb);
		pivot_right(la, lb, i_piv, low_piv - 1); //+possibilites de double rev_rot, a priori non!
		left_sorting(la, lb, i_piv, low_piv - 2); // attention aux conditions particulieres dans la;
		// print_listi(*la, *lb);
	}
}

void	pivot_left(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	while ((*lb) && (*lb)->low_piv <= low_piv + 1 && (*lb)->piv == piv)
	{
						if ((*la)->nbr == 689)
	{
		// ft_printf("\n\n00 - Right Sorting, piv : %d, low_piv : %d, nb_elem_categ ;\
	//  %d, count : %d\n", piv, low_piv, (*la)->nb_elem_categ);
	//  	print_listi(*la, *lb);
	}
		if ((*lb)->low_piv == low_piv + 1)
		{

			// ft_printf("I FEEL ITS HERE    ");
			if ((*la)->low_piv == low_piv) // surveiller le ">= dans des cas particuliers" + eventuellement eviter rr+ rrr si c'est le dernier
				double_rotate(la, lb);
			else if (no_more_low_piv(*lb, piv, low_piv) && no_more_low_piv(*lb, piv, low_piv - 1))
				break ;
			else
				rotate(lb, 'b');
			// if ((*la)->nbr > (*la)->next->nbr)
			// {
			// 	if ((*lb)->nbr < (*lb)->next->nbr)
			// 		double_swap(la, lb);
			// 	else if ((*la)->nb_elem_categ <= 8)
			// 		swap(la, 'a');
			// }
		}
		else
		{
			// split_low_piv(*lb);
			if ((*la)->low_piv == low_piv && (*lb)->low_piv == low_piv - 1)
			{
				while ((*la)->low_piv == low_piv)
					rotate(la, 'a');
			}
			push(la, lb, 'a');
			if ((*la)->nbr > (*la)->next->nbr && (*la)->nb_elem_categ <= 5)
			{
				if ((*lb)->nbr < (*lb)->next->nbr)
					double_swap(la, lb);
				else
					swap(la, 'a');
			}
		}
	}
	while ((*la)->low_piv == low_piv)
		rotate(la, 'a');
}

void	pivot_right(t_listi **la, t_listi **lb, int piv, int low_piv)
{
	// ft_printf("CA SENT LA BOUCLE INFINIE     ");
	while ((*la) && (*la)->low_piv <= low_piv + 1 && (*la)->low_piv >= low_piv - 1 && (*la)->piv == piv)
	{
		
		if ((*la)->low_piv == low_piv )
		{

			if ((*lb)->low_piv == low_piv + 1) // surveiller le ">= dans des cas particuliers" + eventuellement eviter rr+ rrr si c'est le dernier
				double_rotate(la, lb);
			else
				rotate(la, 'a');
			// if ((*la)->nbr > (*la)->next->nbr)
			// {
			// 	if ((*lb)->nbr < (*lb)->next->nbr)
			// 		double_swap(la, lb);
			// 	else if ((*la)->nb_elem_categ <= 8)
			// 		swap(la, 'a');
			// }
		}
		else
		{
			// if (no_more_low_piv(*la, piv, low_piv) && no_more_low_piv(*la, piv, low_piv + 1))
			// 	break ;
			// split_low_piv(*lb);
			if ((*lb)->low_piv == low_piv + 1 && (*la)->low_piv == low_piv - 1)
			{
				while ((*lb)->low_piv == low_piv + 1)
					rotate(lb, 'b');
			}
			push(lb, la, 'b');
			if ((*lb)->nbr < (*lb)->next->nbr && (*lb)->low_piv == (*lb)->next->low_piv && (*lb)->nb_elem_categ <= 5)
			{
				if ((*la)->nbr > (*la)->next->nbr)
					double_swap(la, lb);
				else
					swap(lb, 'b');
			}
		}
	}
	while ((*lb)->low_piv == low_piv + 1)
	{
		// ft_printf("\n\nRight Sorting, NBR : %d, low_piv :\
		 %d, nb_elem_categ ; %d, count : %d\n", (*la)->nbr, low_piv, (*la)->nb_elem_categ);
		rotate(lb, 'b');
	}
	// ft_printf("\n\n00 - Right Sorting, piv : %d, low_piv : %d, nb_elem_categ ;\
	//  %d, count : %d\n", piv, low_piv, (*la)->nb_elem_categ);
	//  	print_listi(*la, *lb);
}