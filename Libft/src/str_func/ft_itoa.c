/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:55:05 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/10 09:28:24 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_str(char *str, unsigned int nb, int len)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		str[len - i - 1] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	str[len - i - 1] = nb % 10 + '0';
}

static int	size(int nb)
{
	int				i;
	unsigned int	nb2;

	i = 1;
	if (nb < 0)
		nb2 = -nb;
	else
		nb2 = nb;
	while (nb2 >= 10)
	{
		nb2 = nb2 / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char			*str;
	int				len;
	unsigned int	nb2;

	len = size(nb);
	if (nb < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb2 = -nb;
		make_str(&str[1], nb2, len - 1);
	}
	else
	{
		nb2 = nb;
		make_str(str, nb2, len);
	}
	return (str);
}
