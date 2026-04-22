/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:16:48 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/23 21:10:56 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	dlen;

	dstlen = 0;
	srclen = 0;
	while (dst[dstlen])
		dstlen++;
	while (src[srclen])
		srclen++;
	dlen = dstlen;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	i = 0;
	while (src[i] && dstlen + 1 < dstsize)
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (dlen + srclen);
}
