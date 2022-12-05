/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:26:22 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/05 19:00:32 by jlitaudo         ###   ########.fr       */
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
	size_t	size;
}t_tab;

typedef struct s_listi
{
	int				nbr;
	struct s_listi	*next;
}t_listi;

void	rev_rotate(t_listi **list);
void	rotate(t_listi **list);
void	push(t_listi **list1, t_listi **list2);
void	swap(t_listi **list);
void	ft_lstadd_front_loc(t_listi **lst, t_listi *new);
void	ft_lstadd_back_loc(t_listi **lst, t_listi *new);
void	sort_merge(t_tab *tab);
int		*make_tab(char **str_tab, size_t size);
t_listi	*ft_lstlast_loc(t_listi *lst);
t_listi	*ft_lstnew_loc(int nbr);
size_t	lst_size_loc(t_listi *lst);
#endif