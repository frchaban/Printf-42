/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <frchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:44:02 by frchaban          #+#    #+#             */
/*   Updated: 2020/05/01 11:44:19 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	free(s1);
	ptr[i] = '\0';
	return (ptr);
}
