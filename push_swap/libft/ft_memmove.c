/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:29:08 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/23 22:40:36 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destn;
	const unsigned char	*srcn;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	destn = dst;
	srcn = src;
	if (destn > srcn)
	{
		while (len--)
		{
			destn[len] = srcn[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			destn[i] = srcn[i];
			i++;
		}
	}
	return (dst);
}
