/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Francois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:35:45 by Francois          #+#    #+#             */
/*   Updated: 2020/04/27 16:51:37 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tronc;

	if (!s)
		return (NULL);
	if (!(tronc = (char *)malloc(sizeof(*tronc) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		tronc[i] = s[start + i];
		i++;
	}
	tronc[len] = '\0';
	return (tronc);
}
