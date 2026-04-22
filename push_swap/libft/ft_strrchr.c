/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:09:59 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/23 21:57:17 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	char			*last;

	a = (unsigned char)c;
	last = NULL;
	while (*s)
	{
		if (*s == a)
			last = (char *)s;
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return (last);
}
