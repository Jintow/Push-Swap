/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/05 19:09:12 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_listi(t_listi *la, t_listi *lb);
void	pivot(t_listi **la, t_listi **lb);

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
	size = size_tab((void **)&argv[1]);
	tab.tab = make_tab(&argv[1], size);
	tab.size = size;
	i = 0;
	while (i < (int)size)
		ft_printf("%d ", tab.tab[i++]);
	ft_printf("\n\n");
	sort_merge(&tab);
	i = 0;
	while (i < (int)size)
		ft_printf("%d ", tab.tab[i++]);
	free(tab.tab);
	
	// while (argv[++i])
	// 	ft_lstadd_back_loc(&la, ft_lstnew_loc(ft_atoi(argv[i])));
	// print_listi(la, lb);
	// while (lst_size_loc(la) > 3)
	// {
	// 	pivot(&la, &lb);
	// 	ft_printf("\n===\nPIVOT\n===\n");
	// 	print_listi(la, lb);
	// }
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
    return (0);

}
/* Peut etre pas oblige de passer avec atoi mais plutot utiliser
strcmp -> permettrait de gerer a la fois les chars et les entiers*/

void	pivot(t_listi **la, t_listi **lb)
{
	t_listi			*temp;
	t_listi			*pivot;
	static unsigned int	i;

	if (!la)
		return ;
	temp = *la;
	while (temp->next)
		temp = temp->next;
	pivot = temp;
	while (*la != pivot)
	{
		if ((*la)->nbr >= pivot->nbr)
			push(lb, la);
		else
			rotate(la);
		i++;
	}
	if ((*la)->next != NULL)
	{
		push(lb, la);
		i++;
	}
	ft_printf("nb op tot: %d\n", i);
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
