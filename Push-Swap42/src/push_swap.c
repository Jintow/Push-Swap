/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/06 20:05:00 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_listi(t_listi *la, t_listi *lb);
void	pivot(t_listi **la, t_listi **lb, t_tab *tab, int i_piv);

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tab;
	size_t	size;
	t_listi	*la;
	t_listi	*lb;

	(void)argc;
	lb = NULL;
	la = NULL;
	i = 0;
	while (argv[++i])
		ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(argv[i])));
	// print_listi(la, lb);
	// ft_printf("\n\n");
	size = size_tab((void **)&argv[1]);
	tab.tab = make_tab(&argv[1], size);
	tab.size = size;
	// AFFICHAGE DU TABLEAU
	// i = 0;
	// while (i < (int)size)
	// 	ft_printf("%d ", tab.tab[i++]);
	// ft_printf("\n\n");
	//AFFCIHAGE DU TABLEAU TRIE INVERSE
	sort_merge(&tab);
	i = -1;
	while (++i < (int)size)
		ft_printf("%d(%d') ", tab.tab[i], i  + 1);
	ft_printf("\n\n");
	//AFFICHAGE DU TABLEAU DES PIVOTS
	make_tab_piv(&tab);
	i = -1;
	ft_printf("\n\n");
	while (++i < (int)tab.size_pivot)
		ft_printf("%d ", tab.tab_pivot[i]);
	// ft_printf("\n %d\n\n", tab.size_pivot);
	//AFFICHAGE DES LISTES MODIFIES PAR LE TAB DES PIVOTS
	i = -1;
	while (++i < (int)tab.size_pivot)
	{
		pivot(&la, &lb, &tab, i);
		ft_printf("\n===\nPIVOT\n===\n");
		print_listi(la, lb);
	}
	free(tab.tab);
	free(tab.tab_pivot);
    return (0);
}
/* Peut etre pas oblige de passer avec atoi mais plutot utiliser
strcmp -> permettrait de gerer a la fois les chars et les entiers*/

void	pivot(t_listi **la, t_listi **lb, t_tab *tab, int i_piv)
{
	int			pivot;
	static unsigned int	i;
	size_t		lst_size;

	if (!la)
		return ;
	pivot = tab->tab_pivot[i_piv];
	lst_size = lst_size_loc(*la);
	while (lst_size-- != 0)
	{
		if ((*la)->nbr > pivot)
			push(lb, la);
		else if ((*la)->nbr == pivot)
		{
			push(lb, la);
			rotate(lb);
		}
		else
			rotate(la);
		i++;
		if (lst_size_loc(*la) == 2)
			break;
	}
	rev_rotate(lb);
	ft_printf("\n\napres pivot (%d) (ci-dessous) : nb op tot: %d\n",pivot, i);
}

void	print_listi(t_listi *la, t_listi *lb)
{
	while (la || lb)
	{
		if (la)
		{
			ft_printf("%d", la->nbr);
			la = la->next;
		}
		ft_printf("\t");
		if (lb)
		{
			ft_printf("%d", lb->nbr);
			lb = lb->next;
		}
		ft_printf("\n");
	}
	ft_printf("---\t---\n a \t b \n");
}

	

	// ft_printf("\n===\nSWAP\n===\n");
    // swap(&la);
	// print_listi(la, lb);
    // ft_printf("\n===\nROTATE\n===\n");
    // rotate(&la);
	// print_listi(la, lb);
    // ft_printf("\n===\nREV_ROTATE\n===\n");
    // rev_rotate(&la);
	// print_listi(la, lb);
    // ft_printf("\n===\nPUSH\n===\n");
    // push(&lb, &la);
	// print_listi(la, lb);
    // ft_printf("\n===\nPUSHb\n===\n");
    // push(&lb, &la);
	// print_listi(la, lb);
    // ft_printf("\n===\nPUSHb\n===\n");
    // push(&lb, &la);
	// print_listi(la, lb);
    // ft_printf("\r===\nrev_rot_b\n===\n");
    // rev_rotate(&lb);
	// print_listi(la, lb);
    // ft_printf("\n===\nPUSHb\n===\n");
    // push(&lb, &la);
	// print_listi(la, lb);
    // ft_printf("\n===\nSWAP_b\n===\n");
    // swap(&lb);
	// print_listi(la, lb);
    // ft_printf("\n===\nPUSHa\n===\n");
    // push(&la, &lb);
	// print_listi(la, lb);
    // ft_printf("\n===\nswap_a\n===\n");
    // swap(&la);
	// print_listi(la, lb);
    // ft_printf("\n===\nrotate a & rotate b\n===\n");
    // rotate(&la);
    // rotate(&lb);
	// print_listi(la, lb);
	// ft_printf("\n===\nPUSHa\n===\n");
	// i = 0;
	// while (i++ < 5)
    // 	push(&la, &lb);
	// print_listi(la, lb);