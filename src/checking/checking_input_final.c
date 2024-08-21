/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_input_final.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:59:48 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/22 12:56:39 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Function that display an error depending on the previous checking.
	If the error does not correspond to a duplicated number nor an 
	overflowed number, an additionnal call to the free function is needed,
	for the previous sorted array created.
*/

void	final_checking(char **tab_nb, t_tab *tab)
{
	int		checking;

	checking = central_checking(tab_nb, tab);
	if (checking < 0)
	{
		free(tab->tab);
		free_tab(tab_nb);
		if (checking == -1)
			exit (0);
		else
		{
			write(2, "Error\n", 6);
			exit (0);
		}
	}
	else if (checking == 0)
	{
		free_tab(tab_nb);
		write(2, "Error\n", 6);
		exit (0);
	}
}
