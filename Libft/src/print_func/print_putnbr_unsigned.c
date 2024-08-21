/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_putnbr_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:10:35 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/12 18:11:36 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putnbr_unsigned(unsigned int n)
{
	int	a;

	if (n >= 10)
	{
		a = print_putnbr_unsigned(n / 10);
		print_putchar(n % 10 + '0');
		return (1 + a);
	}
	print_putchar(n % 10 + '0');
	return (1);
}
