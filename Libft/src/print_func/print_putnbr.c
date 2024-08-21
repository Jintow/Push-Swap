/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:10:35 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/18 12:55:22 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putnbr(int n)
{
	int	a;

	if (n == MIN_INT)
		return (print_putstr("-2147483648"));
	else if (n < 0)
	{
		print_putchar('-');
		return (1 + print_putnbr(-n));
	}
	if (n >= 10)
	{
		a = print_putnbr(n / 10);
		print_putchar(n % 10 + '0');
		return (1 + a);
	}
	print_putchar(n % 10 + '0');
	return (1);
}
