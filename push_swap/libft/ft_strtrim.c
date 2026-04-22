/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:26:59 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/23 22:32:17 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0' && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
			break ;
		i++;
	}
	return ((char *)&s1[i]);
}

char	*ft_end(char const *s1, char const *set, size_t len)
{
	int	k;
	int	j;

	k = len - 1;
	while (k >= 0)
	{
		j = 0;
		while (set[j] != '\0' && s1[k] != set[j])
			j++;
		if (set[j] == '\0')
			break ;
		k--;
	}
	return ((char *)&s1[k + 1]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	len;
	char	*start;
	char	*end;
	char	*copy;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = ft_start(s1, set);
	end = ft_end(s1, set, len);
	if (start >= end)
		return (ft_strdup(""));
	ptr = (char *)malloc((end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	copy = ptr;
	while (start < end)
		*copy++ = *start++;
	*copy = '\0';
	return (ptr);
}
