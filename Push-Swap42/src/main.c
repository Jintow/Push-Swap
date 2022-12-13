/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/13 13:44:44 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tab;
	size_t	size;
	t_listi	*la;
	t_listi	*lb;
	char	**tab_nb;
	int		checking;

	(void)argc;
	lb = NULL;
	la = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		tab_nb = ft_split((argv[1]), ' ');
		checking = central_checking(tab_nb, &tab);
		if (checking <= 0)
		{
			if (checking == -1)
			{
				free(tab.tab);
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
		i = 0;
		while (tab_nb[i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(tab_nb[i++])));
	}
	else
	{
		checking = central_checking(&argv[1], &tab);
		if (checking <= 0)
		{
			if (checking == -1)
			{
				free(tab.tab);
				exit (0);
			}
			else
			{
				write(2, "Error\n", 6);
				exit (0);
			}
		}
		i = 0;
		while (argv[++i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(argv[i])));
	}
	// if (argc == 2)
	// {
	// 	tab_nb = ft_split((argv[1]), ' ');
	// 	size = size_tab((void **)tab_nb);
	// 	tab.tab = make_tab(tab_nb, size);
	// while (tab_nb[i])
	// 	ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(tab_nb[i++])));
	// }
	// else
	// {
	// 	size = size_tab((void **)&argv[1]);
	// 	tab.tab = make_tab(&argv[1], size);
	// 	while (argv[++i])
	// 		ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(argv[i])));
	// }
	// list_initialization(&la, tab_nb);
	// list_initialization(&la, &argv[1]);
	// sort_merge(&tab);
	make_tab_piv(&tab);
	add_infolst(&la, &tab);
	split_categ(&la, tab.size_pivot);
	i = tab.size_pivot;
	while (i > 0)
	{
		if ( i == tab.size_pivot)
			pivot(&la, &lb, i);
		else
			pivot2(&la, &lb, i);
		i--;
	}
	left_sorting(&la, &lb, 1, 0);
	// free(tab.tab);
	// free(tab.tab_pivot);
    return (0);
}
