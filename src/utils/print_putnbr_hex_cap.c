/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_putnbr_hex_cap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:00:24 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/12 18:00:53 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putnbr_hex_cap(unsigned int n)
{
	int	len;

	if (n >= 16)
	{
		len = print_putnbr_hex_cap(n / 16);
		print_putchar(BASE_HEX_CAP[n % 16]);
		return (1 + len);
	}
	print_putchar(BASE_HEX_CAP[n % 16]);
	return (1);
}
