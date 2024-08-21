/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:56:26 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/21 14:06:33 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_tab	tab;
	t_listi	*la;
	char	**tab_nb;

	if (argc == 1)
		return (0);
	la = NULL;
	tab.bonus = 1;
	tab_nb = init_tab(&argv[1]);
	final_checking(tab_nb, &tab);
	create_list(&la, tab_nb);
	free_tab(tab_nb);
	sorting_pilot_bonus(&la, &tab);
}
