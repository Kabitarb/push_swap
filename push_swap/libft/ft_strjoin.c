/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:56:58 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/23 22:40:43 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < lens2)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
