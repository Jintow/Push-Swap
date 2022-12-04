/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:58:50 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/04 01:22:42 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != str)
		i++;
	return (i);
}

unsigned int	ft_atoi_base(char *str)
{
	unsigned int	i;
	unsigned int	nb;


	nb = 0;
	i = 0;
	while (str[i])
		nb = str[i++] - '0'  + (nb * 10);
	return (nb);
}
