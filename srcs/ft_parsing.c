/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <frchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:41:47 by frchaban          #+#    #+#             */
/*   Updated: 2020/05/01 17:49:45 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	ft_format_parsing(const char *fmt, unsigned int pos)
{
	t_format	f;

	f.conv = 0;
	f.flag = 0;
	f.excp = 0;
	f.before = ft_format_before(fmt, pos);
	pos = pos + ft_strlen(f.before) + 1;
	if (pos >= ft_strlen(fmt))
		return (f);
	f = ft_format_flag(f, fmt, pos);
	pos = pos + f.offsetflag;
	f.width = ft_format_width(fmt, pos);
	pos = pos + ft_strlen(f.width);
	if (fmt[pos] == '.' && fmt[pos])
	{
		f.precision = ft_format_precision(fmt, ++pos);
		if (f.precision)
			pos = pos + ft_strlen(f.precision);
	}
	else
		f.precision = NULL;
	if (ft_isconv(fmt[pos]) && fmt[pos])
		f.conv = fmt[pos];
	return (f);
}

t_format	*ft_parsing(const char *fmt)
{
	t_format		*f;
	int				i;
	unsigned int	pos;

	if (!(f = (t_format *)malloc(sizeof(*f) * (ft_count(fmt) + 1))))
		return (NULL);
	i = -1;
	pos = 0;
	while (++i <= (int)ft_count(fmt))
	{
		f[i] = ft_format_parsing(fmt, pos);
		pos += ft_strlen(f[i].before) + 1;
		if (pos >= ft_strlen(fmt))
			break ;
		pos = pos + f[i].offsetflag + ft_strlen(f[i].width);
		if (fmt[pos] == '.' && fmt[pos])
			pos += 1;
		if (fmt[pos - 1] == '.' && !f[i].precision)
			f[i].precision = ft_strdup("0");
		else if (fmt[pos - 1] == '.' && f[i].precision)
			pos += (f[i].precision ? ft_strlen(f[i].precision) : 0);
		pos += 1;
	}
	return (f);
}
