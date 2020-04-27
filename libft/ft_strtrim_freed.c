/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_freed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:42:04 by frchaban          #+#    #+#             */
/*   Updated: 2020/04/27 17:25:40 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_occ(char const *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim_freed(char *s, char const *set)
{
	char			*trim;
	int				start;
	int				end;
	size_t			len;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && ft_occ(set, s[start]) == 1)
		start++;
	end = ft_strlen(s) - 1;
	while (end >= 0 && ft_occ(set, s[end]) == 1)
		end--;
	len = end - start + 1;
	trim = ft_substr(s, start, len);
	if (trim == NULL)
	{
		if (!(trim = (char *)malloc(sizeof(*trim) * 1)))
			return (NULL);
		trim[0] = '\0';
	}
	free(s);
	return (trim);
}
