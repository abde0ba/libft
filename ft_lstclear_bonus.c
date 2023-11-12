/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 03:33:59 by abbaraka          #+#    #+#             */
/*   Updated: 2023/11/05 19:57:46 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst && del)
	{
		ptr = *lst;
		while (*lst)
		{
			*lst = ptr->next;
			del(ptr->content);
			free(ptr);
			ptr = *lst;
		}
		*lst = 0;
	}
}
