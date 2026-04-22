/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 22:04:53 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/20 20:34:34 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	char	*copy;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	copy = ptr;
	while (*s1)
	{
		*copy++ = *s1++;
	}
	*copy = '\0';
	return (ptr);
}
