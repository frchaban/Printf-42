/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <frchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:28:33 by Francois          #+#    #+#             */
/*   Updated: 2020/04/28 16:13:52 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s));
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	if (!s[i])
		return (ft_strdup(""));
	while (s[j] && ft_strchr(set, s[j]))
		j--;
	return (ft_substr(s, i, j - i + 1));
}
