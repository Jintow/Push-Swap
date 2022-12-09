/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/09 20:12:37 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_listi *lst);

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tab;
	size_t	size;
	t_listi	*la;
	t_listi	*lb;
	char	**tab_nb;

	(void)argc;
	lb = NULL;
	la = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		tab_nb = ft_split((argv[1]), ' ');
		// while (tab_nb[i])
		// 	ft_printf("%s ", tab_nb[i++]);
		while (tab_nb[i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(atoi(tab_nb[i++])));
	}
	else
		while (argv[++i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(argv[i])));
	size = size_tab((void **)&argv[1]);
	tab.tab = make_tab(&argv[1], size);
	tab.size = size;
	//AFFCIHAGE DU TABLEAU TRIE inverse, mais indices bon ordre
	sort_merge(&tab);
	i = -1;
	while (++i < (int)size)
		ft_printf("%d(%d') ", tab.tab[size - i - 1], size - i);
	ft_printf("\n\n");
	make_tab_piv(&tab);
	add_infolst(&la, &tab);
	//AFFICHAGE DES LISTES MODIFIES PAR LE TAB DES PIVOTS
	split_categ(&la, tab.size_pivot);
	i = tab.size_pivot;
	while (i > 0)
	{
		if (i == 1)
			if (check_sorted(la))
				break;
		if ( i == tab.size_pivot)
			pivot(&la, &lb, i);
		else
			pivot2(&la, &lb, i);
		i--;
		ft_printf("\n===\nPIVOT\n===\n");
	}
	// print_listi(la, lb);
	left_sorting(&la, &lb, 1, 0);
	ft_printf("\n\n");
	print_listi(la, lb);
	// free(tab.tab);
	// free(tab.tab_pivot);
    return (0);
}

int	check_sorted(t_listi *lst)
{
	while (lst)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}