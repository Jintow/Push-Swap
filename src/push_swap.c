/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:19 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/04 14:21:01 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *la, t_list *lb);

int	main(int argc, char **argv)
{
    int		i;
    t_list	*la;
    t_list	*lb;

    i = 0;
    while (argv[++i])
        ft_lstadd_back(&la, ft_lstnew(ft_atoi_base(argv[i])));
    print_list(la, lb);
	ft_printf("\n===\nSWAP\n===\n");
    swap(&la);
	print_list(la, lb);
    ft_printf("\n===\nROTATE\n===\n");
    rotate(&la);
	print_list(la, lb);
    ft_printf("\n===\nREV_ROTATE\n===\n");
    rev_rotate(&la);
	print_list(la, lb);
    ft_printf("\n===\nPUSH\n===\n");
    push(&lb, &la);
	print_list(la, lb);
    ft_printf("\n===\nPUSHb\n===\n");
    push(&lb, &la);
	print_list(la, lb);
    ft_printf("\n===\nPUSHb\n===\n");
    push(&lb, &la);
	print_list(la, lb);
    ft_printf("\r===\nrev_rot_b\n===\n");
    rev_rotate(&lb);
	print_list(la, lb);
    ft_printf("\n===\nPUSHb\n===\n");
    push(&lb, &la);
	print_list(la, lb);
    ft_printf("\n===\nSWAP_b\n===\n");
    swap(&lb);
	print_list(la, lb);
    ft_printf("\n===\nPUSHa\n===\n");
    push(&la, &lb);
	print_list(la, lb);
    ft_printf("\n===\nswap_a\n===\n");
    swap(&la);
	print_list(la, lb);
    ft_printf("\n===\nrotatea & rotate b\n===\n");
    rotate(&la);
    rotate(&lb);
	print_list(la, lb);
    return (0);

}
/* Peut etre pas oblige de passer avec atoi mais plutot utiliser
strcmp -> permettrait de gerer a la fois les chars et les entiers*/

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