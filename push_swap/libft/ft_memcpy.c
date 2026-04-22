/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:21:02 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/23 22:31:46 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*distn;
	const unsigned char	*srcn;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	distn = dst;
	srcn = src;
	i = 0;
	while (i < n)
	{
		distn[i] = srcn[i];
		i++;
	}
	return (dst);
}
