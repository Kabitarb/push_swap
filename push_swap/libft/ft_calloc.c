/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:43:50 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/14 22:03:46 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	if ((count != 0 && size != 0) && count > SIZE_MAX / size)
	{
		return (NULL);
	}
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (size * count));
	return (p);
}
