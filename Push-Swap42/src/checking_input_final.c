/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_input_final.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:59:48 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 15:29:12 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_checking1(char **tab_nb, t_tab *tab)
{
	int		checking;

	if (size_tab((void **)(tab_nb)) == 1)
	{
		free_tab(tab_nb);
		exit(0);
	}
	checking = central_checking(tab_nb, tab);
	if (checking <= 0)
	{
		if (checking == -1)
		{
			free(tab->tab);
			free_tab(tab_nb);
			exit (0);
		}
		else
		{
			free_tab(tab_nb);
			write(2, "Error\n", 6);
			exit (0);
		}
	}
}

void	final_checking2(char **tab_nb, t_tab *tab)
{
	int		checking;

	if (size_tab((void **)(tab_nb)) == 1)
		exit(0);
	checking = central_checking(tab_nb, tab);
	if (checking <= 0)
	{
		if (checking == -1)
		{
			free(tab->tab);
			exit (0);
		}
		else
		{
			write(2, "Error\n", 6);
			exit (0);
		}
	}
}
