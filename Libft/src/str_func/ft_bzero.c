/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:05:49 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/08 09:10:59 by jlitaudo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
