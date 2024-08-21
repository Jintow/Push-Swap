/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_putnbr_hex_low.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:00:24 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/18 08:45:02 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putnbr_hex_low(unsigned int n)
{
	int	a;

	if (n >= 16)
	{
		a = print_putnbr_hex_low(n / 16);
		print_putchar(BASE_HEX_LOW[n % 16]);
		return (1 + a);
	}
	print_putchar(BASE_HEX_LOW[n % 16]);
	return (1);
}
