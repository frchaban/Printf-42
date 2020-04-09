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

char		*ft_before(const char *fmt, unsigned int pos)
{
	unsigned int	i;

	i = 0;
	while (fmt[pos + i] && fmt[pos + i] != '%')
		i++;
	return (ft_substr(fmt,pos,i));
}

t_format	*ft_parsing(const char *fmt)
{
	unsigned int	w;
	unsigned int	p;
	t_format		*f;
	int				i;
	unsigned int	pos;

	if (!(f = (t_format *)malloc(sizeof(*f) * ft_count(fmt))))
		return (NULL);
	i = -1;
	pos = 0;
	while (++i <= (int)ft_count(fmt))
	{
		w = 0;
		p = 0;
		f[i].before = ft_before(fmt, pos);
		pos = pos + ft_strlen(f[i].before) + 1; 
		if (fmt[pos] && fmt[pos] == '0')
			f[i].flag = fmt[pos++];
		if (fmt[pos] == '-' && fmt[pos])
			f[i].flag = fmt[pos++];
		while (ft_isdigit(fmt[pos + w]) && fmt[pos + w])
			w++;
		if (w != 0)
			f[i].width = (ft_substr(fmt, pos, w));
		if (fmt[pos + w] == '.' && fmt[pos + w])
		{
			while (ft_isdigit(fmt[++pos + w + p]) && fmt[pos + w + p])
				p++;
			if (p != 0)
				f[i].precision = ft_substr(fmt, pos + w - p, p + 1);
		}	
		if (ft_isconv(fmt[pos + w + p]) && fmt[pos + w + p])
			f[i].conv = fmt[pos + w + p];
		pos = pos + w + p + 1;
	}
	return (f);
}
