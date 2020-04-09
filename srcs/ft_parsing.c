/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 15:27:55 by frchaban          #+#    #+#             */
/*   Updated: 2020/03/31 21:09:21 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	ft_initialize(t_format f)
{
	f.flag = 0;
	free(f.width);
	f.width = NULL;
	free(f.precision);
	f.precision = NULL;
	f.conv = 0;
	f.offset = 0;
	return (f);
}

t_format	ft_parsing(const char *fmt, unsigned int pos, t_format f)
{
	unsigned int	w;
	unsigned int	p;

	w = 0;
	p = 0;
	f = ft_initialize(f);
	if (fmt[pos] == '0' && fmt[pos])
		f.flag = fmt[pos++];
	if (fmt[pos] == '-' && fmt[pos])
		f.flag = fmt[pos++];
	while (ft_isdigit(fmt[pos + w]) && fmt[pos + w])
		w++;
	if (w != 0)
		f.width = (ft_substr(fmt, pos, w));
	if (fmt[pos + w] == '.' && fmt[pos + w])
	{
		while (ft_isdigit(fmt[++pos + w + p]) && fmt[pos + w + p])
			p++;
		if (p != 0)
			f.precision = ft_substr(fmt, pos + w, p);
	}	
	if (ft_isconv(fmt[pos + w + p]) && fmt[pos + w + p])
	{
		f.conv = fmt[pos + w + p];
		f.offset = ++pos + w + p;
	}
	printf("%c // %s // %s // %c // %d\n", f.flag, f.width, f.precision, f.conv, f.offset);
	return (f);
}
