/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:07:54 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/23 17:17:44 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	token(char const *s, char c) // token length
{
	int		i;
	int		check;
	size_t	count;

	i = 0;
	check = 1;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && check == 1)
		{
			check = 0;
			count++;
		}
		else if (s[i] == c)
		{
			check = 1;
		}
		i++;
	}
	return (count);
}

size_t	word_len(char const *s, size_t i, char c) // length of string
{
	size_t	count;
	size_t	j;

	j = i;
	count = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			count++;
		}
		else
			break ;
		j++;
	}
	return (count);
}

void	free_space(char **ptr, size_t j)
{
	size_t	k;

	k = 0;
	while (k < j)
	{
		free(ptr[k]);
		k++;
	}
	free(ptr);
}

char	**substring(char const *s, char c, char **ptr, size_t len)
{
	size_t	i;
	size_t	j;
	int		check;
	size_t	lenstr;

	check = 1;
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		if (s[i] != c && check == 1)
		{
			check = 0;
			lenstr = word_len(s, i, c);
			ptr[j] = ft_substr(s, i, lenstr);
			if (!ptr[j])
				return (free_space(ptr, j), NULL);
			j++;
		}
		else if (s[i] == c)
			check = 1;
		i++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
// allocate the memory for each substring
{
	char	**ptr;
	size_t	len;

	if (!s)
		return (NULL);
	len = token(s, c);
	ptr = malloc((len + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr[len] = NULL;
	return (substring(s, c, ptr, len));
}
