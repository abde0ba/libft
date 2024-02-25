/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbaraka <abbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:45:10 by abbaraka          #+#    #+#             */
/*   Updated: 2023/11/15 22:40:55 by abbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	ptr = NULL;
	if (!f || !del || !lst)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(NULL);
		if (!new)
		{
			ft_lstclear(&ptr, del);
			return (NULL); 
		}
		new->content = f(lst->content);
		ft_lstadd_back(&ptr, new);
		lst = lst->next;
	}
	// ft_lstclear(&lst, del);
	return (ptr);
}
