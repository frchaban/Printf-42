/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:32:48 by frchaban          #+#    #+#             */
/*   Updated: 2020/04/27 17:00:21 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *ret;

	(void)(*del);
	if (!lst)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	ret = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = ft_lstnew((*f)(lst->content))))
			return (NULL);
		new = new->next;
	}
	return (ret);
}
