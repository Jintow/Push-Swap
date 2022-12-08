/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/08 15:26:44 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_listi(t_listi *la, t_listi *lb);
void	pivot(t_listi **la, t_listi **lb, int i_piv);
void	pivot2(t_listi **la, t_listi **lb, int i_piv);

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
	if (argc == 2)
	{
		tab_nb = ft_split((argv[1]), ' ');
		while (tab_nb[i++])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(tab_nb[i])));
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
		if ( i == tab.size_pivot)
			pivot(&la, &lb, i);
		else
			pivot2(&la, &lb, i);
		i--;
		ft_printf("\n===\nPIVOT\n===\n");
	}
	print_listi(la, lb);
	// free(tab.tab);
	// free(tab.tab_pivot);
    return (0);
}
