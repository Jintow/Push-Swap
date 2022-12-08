/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/08 13:03:42 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_listi(t_listi *la, t_listi *lb);
void	pivot(t_listi **la, t_listi **lb, int i_piv);
void	pivot2(t_listi **la, t_listi **lb, int i_piv);
void	split_categ(t_listi **lst, int max_piv);

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
	if (argc == 2)
	{
		tab_nb = ft_split((argv[1]), ' ');
		i = 0;
		while (tab_nb[i++])
		ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(tab_nb[i])));
	}
	else
	{
		i = 0;
		while (argv[++i])
			ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(argv[i])));
	}
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
	//AFFICHAGE DES LISTES MODIFIES PAR LE TAB DES PIVOTS
	split_categ(&la, 7);
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
	ft_printf("INCROYABLE");
	return (1);
}

void	pivot(t_listi **la, t_listi **lb, int i_piv)
{
	static unsigned int	i;
	int			j;
	int			k;
	int			lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	j = 0;
	k = 0;
	while (lst_size-- > 0)
	{
		print_listi(*la, *lb);
		if ((*lb) && (*lb)->next && (*lb)->nbr > (*lb)->next->nbr && (*lb)->low_piv == (*lb)->next->low_piv)
		{
			if ((*la)->nbr < (*la)->next->nbr && (*la)->next->low_piv == (*la)->low_piv)
			{
				double_swap(la, lb);
				k++;
			}
			else 
				swap(lb, 'b');
			i++;
		}
		if ((*la)->next->nbr > (*la)->nbr && (*la)->next->low_piv == (*la)->low_piv && (*la)->piv == (*la)->next->piv && !((*la)->piv = i_piv && (*la)->low_piv == 1))
		{
			swap(la, 'a');
			i++;
		}
		if ((*la)->piv == i_piv)
		{
			if ((*lb) && (*lb)->low_piv == 1 && (*lb)->piv == i_piv)
			{
				rotate(lb, 'b');
				i++;
			}
			push(lb, la, 'b');
			// if ((*la)->low_piv == 1 && (*la)->piv == i_piv && (*lb)->low_piv == 1)
			// {
			// 	rotate(lb, 'b');
			// 	i++;
			// }
		}
		else
		{
			if ((*lb) && (*lb)->low_piv == 1 && (*lb)->piv == i_piv)
			{
				j++;
				double_rotate(la, lb);
			}
			else
				rotate(la, 'a');
		}
		i++;
		//print_listi(*la, *lb);
		if (lst_size_loc(*la) == 2 || no_more_piv(*la, i_piv))
			break;
	}
	if ((*lb) && (*lb)->low_piv == 1)
	{
		i++;
		rotate(lb, 'b');
	}
	ft_printf("\n%d : lst_size", lst_size);
	ft_printf("\n\napres pivot (%d) (ci-dessous) : nb op tot: %d, double_rot :%d, double swap :%d\n",i_piv, i, j, k);
}



void	pivot2(t_listi **la, t_listi **lb, int i_piv)
{
	static unsigned int	i;
	static	int			j;
	static	int			k;
	static	int			l;
	int			lst_size;

	if (!(*la))
		return ;
	lst_size = (int)lst_size_loc(*la);
	while (lst_size-- > 0)
	{
		if ((*lb) && (*lb)->next && (*lb)->nbr > (*lb)->next->nbr && (*lb)->low_piv == (*lb)->next->low_piv)
		{
			if ((*la)->nbr < (*la)->next->nbr && (*la)->next->low_piv == (*la)->low_piv)
			{
				double_swap(la, lb);
				k++;
			}
			else 
				swap(lb, 'b');
			i++;
		}
		if ((*la)->next->nbr > (*la)->nbr && (*la)->next->low_piv == (*la)->low_piv && (*la)->piv == (*la)->next->piv)
		{
			swap(la, 'a');
			i++;
		}
		if ((*la)->piv == i_piv)
		{
			if ((*lb) && (*lb)->low_piv == 0 && (*lb)->piv == i_piv)
			{
				rotate(lb, 'b');
				i++;
			}
			push(lb, la, 'b');
		}
		else
		{
			if ((*lb) && (*lb)->low_piv == 0 && (*lb)->piv == i_piv)
			{
				j++;
				double_rotate(la, lb);
			}
			else
				rotate(la, 'a');
		}
		i++;
		if (lst_size_loc(*la) == 2 || no_more_piv(*la, i_piv))
			break;
	}
	ft_printf("\n%d : lst_size\n", lst_size);
	while (ft_lstlast_loc(*lb)->low_piv == 0)
	{
		//ft_printf("OK\n");
		if ((*lb) && (*lb)->next && (*lb)->nbr > (*lb)->next->nbr)
		{
			if ((*la)->nbr < (*la)->next->nbr)
			{
				double_swap(la, lb);
				k++;
			}
			else 
				swap(lb, 'b');
			i++;
		}
		// if (ft_lstlast_loc(*la)->piv == i_piv - 1)
		// {
		double_rev_rotate(la, lb);
		l++;
		// }
		// else
		//rev_rotate(lb, 'b');
		// i++;
	}
	ft_printf("\n\napres pivot (%d) (ci-dessous) : nb op tot: %d, double_rot :%d, double swap :%d, double rev_rot : %d\n",i_piv, i, j, k, l);
}

void	split_categ(t_listi **lst, int max_piv)
{
	int		pos_max;
	t_listi	*temp;
	
	while (max_piv >= 0)
	{
		pos_max = find_max(*lst, max_piv);
		pos_max /= 2;
		temp = *lst;
		while (temp)
		{
			if (temp->piv == max_piv)
			{
				if (temp->pos > pos_max)
				{
					temp->pos -= pos_max;
					temp->low_piv = 1;
				}
				else
					temp->low_piv = 0;
			}
			temp = temp->next;
		}
		max_piv--;
	}
}

void	print_listi(t_listi *la, t_listi *lb)
{
	while (la || lb)
	{
		if (la)
		{
			ft_printf("%d\t([%d][%d][%d])", la->nbr, la->piv, la->low_piv, la->pos);
			la = la->next;
		}
		else
			ft_printf("\t\t");
		if (lb)
		{
			ft_printf("\t");
			ft_printf("%d\t([%d][%d][%d])", lb->nbr, lb->piv, lb->low_piv, lb->pos);
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