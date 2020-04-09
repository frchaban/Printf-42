/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Francois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:28:33 by Francois          #+#    #+#             */
/*   Updated: 2020/03/18 15:49:29 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_occ(char const *set, char c)
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
char	*ft_strtrim(char const *s, char const *set)
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
	return (trim);
}
