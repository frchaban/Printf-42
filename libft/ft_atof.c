/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <frchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 20:53:38 by frchaban          #+#    #+#             */
/*   Updated: 2020/04/27 13:57:56 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

float	ft_atof(const char *str)
{
	int		atoi;
	float	atof;
	int		fac;
	int		i;

	fac = 1;
	i = 0;
	atof = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	atoi = ft_atoi(str);
	i += ft_len_int(atoi);
	if (str[i] == '.')
		i++;
	else
		return (atoi);
	while (str[i] && ft_isdigit(str[i]))
	{
		fac *= 10;
		atof = atof * 10 + (str[i++] - 48);
	}
	if (atoi < 0)
		return (atoi - atof / fac);
	return (atoi + atof / fac);
}
