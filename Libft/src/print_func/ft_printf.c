/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:35:31 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/05 10:41:25 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

static int	print_argument(char c, va_list args)
{
	if (c == 'c')
		return (print_putchar(va_arg(args, int)));
	else if (c == 's')
		return (print_putstr(va_arg(args, char *)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (2 + print_pointer(va_arg(args, unsigned long long)));
	}
	else if (c == 'd')
		return (print_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (print_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (print_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_putnbr_hex_low(va_arg(args, int)));
	else if (c == 'X')
		return (print_putnbr_hex_cap(va_arg(args, int)));
	else if (c == '%')
		return (print_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (write(1, NULL, 0) != 0)
		return (-1);
	va_start(args, text);
	len = 0;
	i = 0;
	while (text[i])
	{
		if (text[i] != '%')
		{
			write(1, &text[i], 1);
			len++;
		}
		else if (text[i + 1])
		{
			len += print_argument(text[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
