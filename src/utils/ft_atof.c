/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teiki <Teiki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:22:44 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/03 18:39:53 by Teiki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_atof(char *str)
{
	float	nb;
	float	sign;
	int		base;
	int		i;

	nb = 0.0;
	sign = 1.0;
	base = 10;
	i = 0;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	nb = (float)(str[i] - '0');
	if (!str[i + 1] || !str[i + 2])
		return (sign * nb);
	i += 2;
	while (str[i] && i < 8)
	{
		nb += ((float)(str[i] - '0')) / base;
		base *= 10;
		i++;
	}
	return (sign * nb);
}
