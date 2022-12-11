/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/11 16:47:08 by Teiki            ###   ########.fr       */
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
		size = size_tab((void **)tab_nb);
		tab.tab = make_tab(tab_nb, size);
		while (tab_nb[i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(tab_nb[i++])));
	}
	else
	{
		size = size_tab((void **)&argv[1]);
		tab.tab = make_tab(&argv[1], size);
		while (argv[++i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(argv[i])));
	}
	tab.size = size;
	sort_merge(&tab);
	i = -1;
	// while (++i < (int)size)
	// 	ft_printf("%d(%d') ", tab.tab[size - i - 1], size - i);
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
	ft_printf("BEGINNING SORTING");
	left_sorting(&la, &lb, 1, 0);
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