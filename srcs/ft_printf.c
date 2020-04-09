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

	f = ft_parsing(format);
	va_start(ap, format);
	i = -1;
	while (++i < (int)ft_count(format))
	{	
		/*ft_putstr(f[i].before);
		if (f[i].conv == 'd' || f[i].conv == 'i' || f[i].conv == 'u')
			ft_putnbr(va_arg(ap, int));
		else if (f[i].conv == 'x' || f[i].conv == 'X')
			ft_putnbr_hex_US(va_arg(ap, int), f[i].conv =='x' ? 1 : 2);
		else if (f[i].conv == 'c')
			ft_putchar(va_arg(ap, int));
		else if (f[i].conv == 's')
			ft_putstr(va_arg(ap, char *));
		else if (f[i].conv == 'p')
			ft_putnbr_hex_US((long)va_arg(ap, unsigned int), 1);
		else if (f[i].conv == '%')
			ft_putchar('%');
			*/
		printf("before: %s\n" ,f[i].before);
		printf("flag: %c\n" ,f[i].flag);
		printf("width: %s\n" ,f[i].width);
		printf("precision: %s\n" ,f[i].precision);
		printf("conv: %c\n" ,f[i].conv);
	}
	printf("before: %s\n" ,f[i].before);
	va_end(ap);
	return (0);
}

