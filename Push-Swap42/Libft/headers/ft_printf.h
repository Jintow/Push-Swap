/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:32:57 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/12/05 08:57:18 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define BASE_HEX_LOW "0123456789abcdef"
# define BASE_HEX_CAP "0123456789ABCDEF"
# define MIN_INT -2147483648

int		ft_printf(const char *text, ...);
int		print_putchar(char c);
int		print_putstr(char *s);
int		print_putnbr(int n);
int		print_pointer(unsigned long long n);
int		print_putnbr_hex_low(unsigned int n);
int		print_putnbr_hex_cap(unsigned int n);
int		print_putnbr_unsigned(unsigned int n);

#endif