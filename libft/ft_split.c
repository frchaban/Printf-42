/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Francois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:35:10 by Francois          #+#    #+#             */
/*   Updated: 2020/04/27 16:55:44 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, unsigned int pos, char c)
{
	unsigned int	i;

	i = 0;
	while (s[pos + i] && s[pos + i] != c)
		i++;
	return (i);
}

static size_t	ft_len(char const *s, char c)
{
	unsigned int	cpt;
	unsigned int	i;
	size_t			len;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_wordlen(s, i, c);
			cpt++;
			i = i + len;
		}
		else
			i++;
	}
	return (cpt);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	cpt;
	char			**split;
	unsigned int	i;
	size_t			len;

	if (s == NULL)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(*split) * (ft_len(s, c) + 1))))
		return (NULL);
	cpt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_wordlen(s, i, c);
			split[cpt] = ft_substr(s, i, len);
			cpt++;
			i = i + len;
		}
		else
			i++;
	}
	split[cpt] = 0;
	return (split);
}
