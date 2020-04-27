/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_freed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 15:00:34 by frchaban          #+#    #+#             */
/*   Updated: 2020/04/27 13:59:06 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_freed(char *str)
{
	int				res;
	unsigned int	i;
	int				neg;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			neg = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - 48);
	if (res < 0 && neg > 0)
		return (-1);
	else if (res < 0 && neg < 0 && res * neg != -2147483648)
		return (0);
	free(str);
	return (res * neg);
}
