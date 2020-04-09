/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Francois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:51:01 by Francois          #+#    #+#             */
/*   Updated: 2020/03/11 14:04:39 by Francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	if (!s || !(*f))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(s[i]);	
		i++;
	}
	str[ft_strlen(s)] = '\0';
	return (str);
}
