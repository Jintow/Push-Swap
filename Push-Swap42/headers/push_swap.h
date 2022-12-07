/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:26:22 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/07 13:39:47 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_tab
{
	int		*tab;
	int		*tab_pivot_ind;
	int		*tab_pivot;
	size_t	size_pivot;
	size_t	size_temp;
	size_t	size;
}t_tab;

typedef struct s_listi
{
	struct s_listi	*next;
	int				nbr;
	int				piv;
	int				ind_max;
	int				pos;
}t_listi;

// typedef struct s_listsmpl
// {
// 	struct s_listsmpl	*next;
// 	t_listi				**lst;
// 	size_t				size;
// 	int					min;
// 	int					pivot;
// 	int					max;
// 	int					sign;
// 	int					first;

// }t_listsmpl;

void	rev_rotate(t_listi **list);
void	double_rev_rotate(t_listi **la, t_listi **lb);
void	rotate(t_listi **list);
void	double_rotate(t_listi **la, t_listi **lb);
void	push(t_listi **list1, t_listi **list2);
void	swap(t_listi **list);
void	double_swap(t_listi **la, t_listi **lb);
void	ft_lstadd_front_loc(t_listi **lst, t_listi *new);
void	ft_lstadd_back_loc(t_listi **lst, t_listi *new);
void	sort_merge(t_tab *tab);
int		*make_tab(char **str_tab, size_t size);
void	make_tab_piv(t_tab	*tab);
void	add_infolst(t_listi **list, t_tab *tab);
t_listi	*ft_lstlast_loc(t_listi *lst);
t_listi	*ft_lstnew_loc(int nbr);
size_t	lst_size_loc(t_listi *lst);
#endif