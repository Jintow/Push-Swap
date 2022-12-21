/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_input_final.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:59:48 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/21 13:39:33 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
