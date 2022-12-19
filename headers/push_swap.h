/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:26:22 by Teiki             #+#    #+#             */
/*   Updated: 2022/12/19 13:57:46 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_tab
{
	int		*tab;
	int		*tab_pivot_ind;
	int		*tab_pivot;
	int		bonus;
	size_t	size_pivot;
	size_t	size_temp;
	size_t	size;
}t_tab;

typedef struct s_listi
{
	struct s_listi	*next;
	int				nbr;
	int				piv;
	int				low_piv;
	int				pos;
	int				nb_elem_categ;
}t_listi;

typedef struct s_nb_elem
{
	int		i;
	int		j;
	int		k;
}t_nb_elem;

/* ------------- SORTING FUNCTIONS -----------------*/

void	pivot(t_listi **la, t_listi **lb, int i_piv);
void	pivot2(t_listi **la, t_listi **lb, int i_piv);
void	pivot_la(t_listi **la, t_listi **lb, int piv, int low_piv);
void	pivot_lb(t_listi **la, t_listi **lb, int piv, int low_piv);
void	sorting_pilot(t_listi **la, t_tab *tab);
void	sorting_la(t_listi **la, t_listi **lb, int i_piv, int low_piv);
void	sorting_lb(t_listi **la, t_listi **lb, int i_piv, int low_piv);
void	init_sorting_lb(t_listi **la, t_listi **lb, int piv, int low_piv);
void	init_sorting_la(t_listi **la, t_listi **lb, int piv, int low_piv);
void	re_index_la(t_listi **la, int low_piv);
void	re_index_lb(t_listi **lst, int piv, int low_piv, int nb);
void	split_categ_sorting(t_listi **lst, int piv, int low_piv, int max);
int		no_more_piv(t_listi	*lst, int piv);
int		no_more_low_piv(t_listi	*lst, int i_piv, int low_piv);
int		count_elem_in_categ(t_listi	**lst, int piv, int low_piv);
void	check_and_pull_back_lb(t_listi **la, t_listi **lb, \
	int piv, int low_piv);
void	check_and_pull_back_la(t_listi **la, t_listi **lb, \
	int piv, int low_piv);

/* -------------- INTIALIZATION FUNCTIONS -----------------*/

void	final_checking(char **tab_nb, t_tab *tab);
void	sort_merge(t_tab *tab);
void	make_tab_piv(t_tab	*tab);
void	split_categ(t_listi **lst, int max_piv);
void	add_infolst(t_listi **list, t_tab *tab);
void	gate_away(t_listi **la, t_listi **lb);
void	print_listi(t_listi *la, t_listi *lb);
int		central_checking(char **tab_nb, t_tab *tab);
int		overflowed_nb(char *nb, int sign);
int		*make_tab(char **str_tab, size_t size);

/* -------------- UTILS FUNCTIONs -----------------*/

void	rev_rotate(t_listi **list, char c);
void	double_rev_rotate(t_listi **la, t_listi **lb);
void	rotate(t_listi **list, char c);
void	double_rotate(t_listi **la, t_listi **lb);
void	push(t_listi **list1, t_listi **list2, char c);
void	swap(t_listi **list, char c);
void	double_swap(t_listi **la, t_listi **lb);

/* ------------- LOCAL LIST FUNCTION -----------------*/

t_listi	*ft_lstlast_loc(t_listi *lst);
t_listi	*ft_lstnew_loc(int nbr);
size_t	lst_size_loc(t_listi *lst);
void	ft_lstclear_loc(t_listi **lst);
void	ft_lstadd_front_loc(t_listi **lst, t_listi *new);
void	ft_lstadd_back_loc(t_listi **lst, t_listi *new);

#endif