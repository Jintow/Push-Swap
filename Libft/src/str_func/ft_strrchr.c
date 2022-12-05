/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlitaudo <jlitaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:19:48 by jlitaudo          #+#    #+#             */
/*   Updated: 2022/11/11 11:45:30 by jlitaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	len;

	len = ft_strlen((char *)str);
	i = 0;
	while (i <= len && str[len - i] != (char)c)
		i++;
	if (str[len - i] == (char)c)
		return (&((char *)str)[len - i]);
	return (NULL);
}
