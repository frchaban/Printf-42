/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Francois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:04:41 by Francois          #+#    #+#             */
/*   Updated: 2020/03/25 17:20:55 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)src == (unsigned char )c)
		{
			*(unsigned char *)dst++ = *(unsigned char *)src++;
			return (dst);
		}
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (NULL);
}
