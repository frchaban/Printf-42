/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_US.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:13:10 by frchaban          #+#    #+#             */
/*   Updated: 2020/03/31 16:21:45 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex_US(unsigned int nbr, int flag)
{
	unsigned long	nb;
	char			*base;

	if (flag == 2)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	nb = nbr;
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_hex_US(nb / ft_strlen(base), flag);
		ft_putnbr_hex_US(nb % ft_strlen(base), flag);
	}
	else
	{
		ft_putchar(base[nb]);
	}
	free (base);
}
