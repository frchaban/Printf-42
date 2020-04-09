/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Francois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:18:26 by Francois          #+#    #+#             */
/*   Updated: 2020/03/25 17:08:30 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (!needle && !haystack)
		return ((char*)haystack);
	if ( needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] && haystack[i + j])
		{
			if (needle[j] == haystack[i + j])
				j++;
			if (needle[j] != haystack[i + j])
				break ;
		}
		if (j == ft_strlen(needle))
		{
			return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
