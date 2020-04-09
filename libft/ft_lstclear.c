/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 12:39:17 by frchaban          #+#    #+#             */
/*   Updated: 2020/03/18 14:28:07 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *begin;
	t_list *tmp;
	if (!lst)
		return ;
	begin = *lst;
	while (begin)
	{
		(*del)(begin->content);
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
	*lst = NULL;
}
