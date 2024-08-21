/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2023/04/13 12:10:22 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	**init_tab(char **argv);
void	create_list(t_listi	**la, char **tab_nb);

int	main(int argc, char **argv)
{
	t_tab	tab;
	t_listi	*la;
	char	**tab_nb;

	if (argc == 1)
		return (0);
	la = NULL;
	tab.bonus = 0;
	tab_nb = init_tab(&argv[1]);
	final_checking(tab_nb, &tab);
	create_list(&la, tab_nb);
	free_tab(tab_nb);
	sorting_pilot(&la, &tab);
}
