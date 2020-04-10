/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 15:41:28 by frchaban          #+#    #+#             */
/*   Updated: 2020/03/31 20:49:07 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int i;
	t_format	*f;
	int	result;

	f = ft_parsing(format);
	va_start(ap, format);
	i = -1;
	while (++i <= (int)ft_count(format))
	{	
		f[i].result = NULL;
		if (f[i].conv == 'd' || f[i].conv == 'i'||f[i].conv == 'x'
		|| f[i].conv == 'X' || f[i].conv == 'c'|| f[i].conv == 'u')
			f[i].result = ft_display_int(f[i], va_arg(ap, int));
		else if (f[i].conv == 'p')
			f[i].result = ft_display_mem(f[i], (long)va_arg(ap, void *));
		else if (f[i].conv == 's')
			f[i].result = ft_display_str(f[i], va_arg(ap, char *));
		else if (f[i].conv == '%')
			f[i].result = ft_strdup("%");
	}
	va_end(ap);
	i = -1;
	result = 0;
	while (++i <= (int)ft_count(format))
	{
		if (f[i].before)
		{
			ft_putstr(f[i].before);
			result += ft_strlen(f[i].before);
		}
		if (f[i].result)
		{
			ft_putstr(f[i].result);
			result += ft_strlen(f[i].result);
		}
	}
	return (result);
}

