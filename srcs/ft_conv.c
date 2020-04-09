/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:49:19 by frchaban          #+#    #+#             */
/*   Updated: 2020/03/28 16:50:29 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int ft_count(const char *format)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

int	ft_isconv(char c)
{
	unsigned int i;
	
	i = 0;
	while (CONV[i])
	{
		if (c == CONV[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_isflag(char c)
{
	unsigned int i;
	
	i = 0;
	while (FLAG[i])
	{
		if (c == FLAG[i])
			return (1);
		i++;
	}
	return (0);
}
