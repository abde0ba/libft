/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:01:24 by abbaraka          #+#    #+#             */
/*   Updated: 2023/11/11 12:59:12 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while ((check_set(s1[start], set) == 1) && (start <= end))
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while ((check_set(s1[end], set) == 1) && (end >= 0))
		end--;
	ptr = (char *)malloc(end - start + 2);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], end - start + 2);
	return (ptr);
}
