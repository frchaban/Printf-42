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

t_format	ft_format_result(va_list ap, t_format f)
{
	f.result = NULL;
	if (f.width && ft_strcmp(f.width, "*") == 0)
		f.width = ft_itoa(va_arg(ap, int));
	if (f.precision && ft_strcmp(f.precision, "*") == 0)
		f.precision = ft_itoa(va_arg(ap, int));	
	if (f.conv == 'd' || f.conv == 'i'||f.conv == 'x'
	|| f.conv == 'X' || f.conv == 'c'|| f.conv == 'u')
		f.result = ft_display_int(f, va_arg(ap, int));
	else if (f.conv == 'p')
		f.result = ft_display_mem(f, (long)va_arg(ap, void *));
	else if (f.conv == 's')
		f.result = ft_display_str(f, va_arg(ap, char *));
	else if (f.conv == '%')
		f.result = ft_display_char(f, '%');
	return (f);
}

int	ft_print_result(t_format *f, int size)
{
	int	result;
	int i;

	i = -1;
	result = 0;
	f[size].result = NULL; 
	while (++i <= size)
	{
		if (f[i].before)
		{
			ft_putstr(f[i].before);
			result += ft_strlen(f[i].before);
		}
		if (f[i].result)
		{
			ft_putstr(f[i].result);
			if (f[i].conv == 'c' && ft_strlen(f[i].result) == 0)
				result +=1;
			else
				result += ft_strlen(f[i].result);
		}
	}
	return (result);
}

void	ft_format_free(t_format *f, unsigned int size)
{
	unsigned int i;
	
	i = 0;
	while (i < size)
	{
		if (f[i].before)
			free(f[i].before);
		if (f[i].width)
			free(f[i].width);
		if (f[i].precision)
			free(f[i].precision);
		if (f[i].result)
			free(f[i].result);
		i++;
	}
	free(f[i].before);
	free(f[i].result);
	if (f)
		free (f);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int i;
	t_format	*f;
	int	result;

	f = ft_parsing(format);
	va_start(ap, format);
	i = -1;
	while (++i < (int)ft_count(format))
		f[i] = ft_format_result(ap, f[i]);
	va_end(ap);
	result = ft_print_result(f, (int)ft_count(format));
	ft_format_free(f, ft_count(format));
	return (result);
}

