/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:38:23 by frchaban          #+#    #+#             */
/*   Updated: 2020/04/27 18:41:21 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_display_char(t_format f, char c)
{
	char	*result;
	char	*offset;

	if (c == 0)
		result = ft_strdup("\0");
	else
	{
		if (!(result = (char *)malloc(sizeof(*result) * 2)))
			return (NULL);
		result[0] = c;
		result[1] = '\0';
	}
	if (f.conv == '%' && f.flag == '0')
		result = ft_length(ft_itoa(ft_atoi(f.width)), result);
	if ((offset = ft_offset(f.width, result)))
		result = (f.flag == '-' ? ft_strjoin_freed(result, offset) :
				ft_strjoin_freed(offset, result));
	return (result);
}

char	*ft_display_d_i(t_format f, char *str)
{
	char	*result;
	char	*offset;

	if (f.conv == 'p')
		str = ft_strjoin_freed(ft_strdup("0x"), str);
	if (f.precision && ft_strcmp(f.precision, "0") == 0)
		if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "-0") == 0)
			return (result = ft_strdup(""));
	result = ft_length(f.precision, str);
	if (!f.precision && f.flag == '0' && result[0] == '-' && f.width)
		result = ft_length(ft_itoa(ft_atoi(f.width) - 1), result);
	else if (!f.precision && f.flag == '0' && f.width)
		result = ft_length(ft_itoa(ft_atoi(f.width)), result);
	else if ((offset = ft_offset(f.width, result)))
		result = (f.flag == '-' ? ft_strjoin_freed(result, offset) :
				ft_strjoin_freed(offset, result));
	return (result);
}

char	*ft_display_mem(t_format f, long arg)
{
	return (ft_display_d_i(f, ft_lhex(arg, 'x')));
}

char	*ft_display_int(t_format f, int arg)
{
	if (f.conv == 'c')
		return (ft_display_char(f, (char)arg));
	else if (f.conv == 'd' || f.conv == 'i')
		return (ft_display_d_i(f, ft_itoa(arg)));
	else if (f.conv == 'u')
		return (ft_display_d_i(f, ft_itoa_us(arg + 1 + 4294967295)));
	else if (f.conv == 'x' || f.conv == 'X')
		return (ft_display_d_i(f, ft_uhex(arg + 1 + 4294967295, f.conv)));
	return (NULL);
}

char	*ft_display_str(t_format f, char *str)
{
	int		size;
	char	*result;
	char	*offset;

	if (!str)
		str = ft_strdup("(null)");
	else if (ft_strcmp(str, "") == 0)
		str = ft_strdup("");
	size = (f.precision ? ft_atoi(f.precision) : ft_strlen(str));
	result = ft_substr(str, 0, size);
	if ((offset = ft_offset(f.width, result)))
		result = (f.flag == '-' ? ft_strjoin_freed(result, offset) :
				ft_strjoin_freed(offset, result));
	return (result);
}
