/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/03/06 11:56:34 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		ptr[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((count > 0) && (size > 0))
		if ((count * size) % size != 0 \
			|| (count * size) % count != 0)
			return (NULL);
	ptr = (void *)malloc (sizeof(char) * count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		digit_found;

	num = 0;
	sign = 1;
	digit_found = 1;
	while (*str == ' ' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+' )
		str++;
	while (*str && digit_found)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + *str - '0';
		else
			digit_found = 0;
		str++;
	}
	return (sign * num);
}
