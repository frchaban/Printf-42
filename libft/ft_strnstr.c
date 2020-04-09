/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Francois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:24:20 by Francois          #+#    #+#             */
/*   Updated: 2020/03/25 17:09:16 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (!needle && !haystack)
		return ((char *)haystack);
	if ((needle[i] == '\0' && len == 0))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && (i + j < len))
		{
			if (needle[j] == haystack[i + j])
				j++;
			if (needle[j] != haystack[i + j])
				break ;
		}
		if (j == ft_strlen(needle))
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
