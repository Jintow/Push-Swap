/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/07 15:34:34 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_listi(t_listi *la, t_listi *lb);
void	pivot(t_listi **la, t_listi **lb, int i_piv);

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
	//AFFCIHAGE DU TABLEAU TRIE inverse, mais indices bon ordre
	sort_merge(&tab);
	i = -1;
	while (++i < (int)size)
		ft_printf("%d(%d') ", tab.tab[size - i - 1], size - i);
	ft_printf("\n\n");
	i = -1;
	//AFFICHAGE DU TABLEAU DES PIVOTS
	make_tab_piv(&tab);
	while (++i < (int)tab.size_pivot)
		ft_printf("%d(%d') ", tab.tab_pivot[i], tab.tab_pivot_ind[i + 1]);
	ft_printf("\nok\n");
	i = -1;
	ft_printf("\n\n");
	while (++i < (int)tab.size_pivot)
		ft_printf("%d ", tab.tab_pivot[i]);
	ft_printf("\n %d\n\n", tab.size_pivot);
	add_infolst(&la, &tab);
	//print_listi(la, lb);
	//AFFICHAGE DES LISTES MODIFIES PAR LE TAB DES PIVOTS
	pivot(&la, &lb, 7);
	print_listi(la, lb);
	// i = -1;
	// while (++i < (int)tab.size_pivot)
	// {
	// 	pivot(&la, &lb, tab.size_pivot - i);
	// 	ft_printf("\n===\nPIVOT\n===\n");
	// }
	// print_listi(la, lb);
	// free(tab.tab);
	// free(tab.tab_pivot);
    return (0);
}
/* Peut etre pas oblige de passer avec atoi mais plutot utiliser
strcmp -> permettrait de gerer a la fois les chars et les entiers*/

int	find_max(t_listi *la, int piv)
{
	int	max;
	
	max = 0;
	while (la)
	{
		if (la->piv == piv && la->pos > max)
			max = la->pos;
		la = la->next;
	}
	return (max);
}

int	no_more_piv(t_listi	*lst, int piv)
{
	while (lst)
	{
		if (lst->piv == piv)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	pivot(t_listi **la, t_listi **lb, int i_piv)
{
	static unsigned int	i;
	int			j;
	int			k;
	int			max;
	int			lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	max =  find_max(*la, i_piv);
	j = 0;
	k = 0;
	while (lst_size-- > 0)
	{
		if ((*lb) && (*lb)->next && (*lb)->pos < (*lb)->next->pos)
			{
				if ((*la)->nbr > (*la)->next->nbr)
					double_swap(la, lb);
				else 
					swap(lb);
				i++;
				k++;
			}
		if ((*la)->piv == i_piv)
			push(lb, la);
		else
		{
			if ((*lb) && (*lb)->piv == i_piv && (*lb)->pos > max / 2)
			{
				j++;
				rotate(la);
				rotate(lb);
			// 	double_rotate(lb, la);
			}
			else
				rotate(la);
		}
		i++;
		//print_listi(*la, *lb);
		if (lst_size_loc(*la) == 2 || no_more_piv(*la, i_piv))
			break;
	}
	ft_printf("\n\napres pivot (%d) (ci-dessous) : nb op tot: %d, double_rot :%d, double swap :%d\n",i_piv, i, j, k);
}

void	print_listi(t_listi *la, t_listi *lb)
{
	while (la || lb)
	{
		if (la)
		{
			ft_printf("%d\t([%d][%d])", la->nbr, la->piv, la->pos);
			la = la->next;
		}
		else
			ft_printf("\t\t");
		if (lb)
		{
			ft_printf("\t");
			ft_printf("%d\t([%d][%d])", lb->nbr, lb->piv, lb->pos);
			lb = lb->next;
		}
		ft_printf("\n");
	}
	ft_printf("-----------------\t------------------\n\ta\t\t\tb\t\n");
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