/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krajbans <krajbans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:57:02 by krajbans          #+#    #+#             */
/*   Updated: 2025/11/23 21:32:59 by krajbans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	length(long long n, char sign)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	if (sign)
		len++;
	return (len);
}

char	*zero(void)
{
	char	*ptr;

	ptr = malloc(2 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	size_t		len;
	char		sign;
	long long	num;

	num = n;
	len = 0;
	if (num == 0)
		return (zero());
	sign = (num < 0);
	if (num < 0)
		num = -num;
	len = length(num, sign);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (len > 0)
	{
		ptr[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (sign)
		ptr[0] = '-';
	return (ptr);
}
