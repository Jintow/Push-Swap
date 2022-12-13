/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:56:26 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 20:06:48 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tab;
	t_listi	*la;
	char	**tab_nb;

	la = NULL;
	if (argc == 1)
		return (0);
	i = 0;
	if (argc == 2)
	{
		tab_nb = ft_split((argv[1]), ' ');
		final_checking1(tab_nb, &tab);
		while (tab_nb[i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(tab_nb[i++])));
		free_tab(tab_nb);
	}
	else
	{
		final_checking2(&argv[1], &tab);
		while (argv[++i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(argv[i])));
	}
	sorting_pilot_bonus(&la, &tab);
	return (0);
}
