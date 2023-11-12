/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:28:11 by abbaraka          #+#    #+#             */
/*   Updated: 2023/11/10 17:24:46 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int n)
{
	int	counter;

	counter = 0;
	while (n / 10)
	{
		counter++;
		n /= 10;
	}
	counter += 1;
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		count;
	long	nb;

	count = count_num(n);
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		count++;
	}
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr[count--] = '\0';
	while (count >= 0)
	{
		ptr[count] = nb % 10 + 48;
		nb /= 10;
		count--;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
