/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/04 22:14:27 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *la, t_list *lb);
void	pivot(t_list **la, t_list **lb);

int	main(int argc, char **argv)
{
    int		i;
    t_list	*la;
    t_list	*lb;

    i = 0;
    while (argv[++i])
        ft_lstadd_back(&la, ft_lstnew(ft_atoi_base(argv[i])));
    print_list(la, lb);
	while (lst_size(la) > 2)
	{
		pivot(&la, &lb);
		ft_printf("\n===\nPIVOT\n===\n");
		print_list(la, lb);
	}
	// ft_printf("\n===\nSWAP\n===\n");
    // swap(&la);
	// print_list(la, lb);
    // ft_printf("\n===\nROTATE\n===\n");
    // rotate(&la);
	// print_list(la, lb);
    // ft_printf("\n===\nREV_ROTATE\n===\n");
    // rev_rotate(&la);
	// print_list(la, lb);
    // ft_printf("\n===\nPUSH\n===\n");
    // push(&lb, &la);
	// print_list(la, lb);
    // ft_printf("\n===\nPUSHb\n===\n");
    // push(&lb, &la);
	// print_list(la, lb);
    // ft_printf("\n===\nPUSHb\n===\n");
    // push(&lb, &la);
	// print_list(la, lb);
    // ft_printf("\r===\nrev_rot_b\n===\n");
    // rev_rotate(&lb);
	// print_list(la, lb);
    // ft_printf("\n===\nPUSHb\n===\n");
    // push(&lb, &la);
	// print_list(la, lb);
    // ft_printf("\n===\nSWAP_b\n===\n");
    // swap(&lb);
	// print_list(la, lb);
    // ft_printf("\n===\nPUSHa\n===\n");
    // push(&la, &lb);
	// print_list(la, lb);
    // ft_printf("\n===\nswap_a\n===\n");
    // swap(&la);
	// print_list(la, lb);
    // ft_printf("\n===\nrotate a & rotate b\n===\n");
    // rotate(&la);
    // rotate(&lb);
	// print_list(la, lb);
    return (0);

}
/* Peut etre pas oblige de passer avec atoi mais plutot utiliser
strcmp -> permettrait de gerer a la fois les chars et les entiers*/

void	pivot(t_list **la, t_list **lb)
{
	t_list			*temp;
	t_list			*pivot;
	unsigned int	size;
	unsigned int 	i;

	if (!la)
		return;
	size = 1;
	temp = *la;
	while (temp->next)
	{
		temp = temp->next;
		size++;
	}
	pivot = temp;
	i = 0;
	while (*la != pivot)
	{
		if ((*la)->nbr[0] >= pivot->nbr[0])
			push(lb, la);
		else
			rotate(la);
	}
	if (pivot->next != NULL)
		push(lb, la);
}

void	print_list(t_list *la, t_list *lb)
{
    while (la || lb)
    {
        if (la)
        {
            ft_printf("%d", la->nbr[0]);
            la = la->next;
        }
        ft_printf("\t");
        if (lb)
        {
            ft_printf("%d", lb->nbr[0]);
            lb = lb->next;
        }
        ft_printf("\n");
    }
	ft_printf("---\t---\n a \t b \n");
}