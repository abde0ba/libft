/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:33:59 by abbaraka          #+#    #+#             */
/*   Updated: 2023/11/11 23:20:29 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	if (!dstsize && !dst)
		return (ft_strlen(src));
	j = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	if ((dstsize > 0) && (dlen < dstsize - 1))
	{
		while (src[j] && (dlen + j < dstsize - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	if (dlen >= dstsize)
		dlen = dstsize;
	return (dlen + slen);
}
