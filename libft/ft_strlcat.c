/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Francois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:11:24 by Francois          #+#    #+#             */
/*   Updated: 2020/03/12 12:14:16 by Francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int len_dest;
	unsigned int len_src;
	unsigned int max;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dest)
	{
		max = dstsize + len_src;
	}
	else
	{
		max = len_src + len_dest;
	}
	i = 0;
	while (src[i] != '\0' && ((len_dest + i + 1) < dstsize))
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	if (dstsize != 0 && len_dest <= dstsize)
		dst[len_dest + i] = '\0';
	return (max);
}
