/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:28:49 by frchaban          #+#    #+#             */
/*   Updated: 2020/03/31 21:09:37 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main(void)
{
   	// ft_printf("char= %c\nstring= %s\nint= %d\nint 2= %i\nhex min= %x\nhex maj= %X\nbullshit= %%\nunsigned int= %u\n", 'A', "salut", 150, 10, 30, 30, 150);
   	 //printf("char= %c\nstring= %s\nint= %d\nint 2= %i\nhex min= %x\nhex maj= %X\nbullshit= %%\nunsigned int= %u\n", 'A', "salut", 150, 10, 30, 30, 150);
	ft_printf("salut%0-53.12ctoi%acoucou%6.234s", "salut");
	//printf("salut%0-53.12ctoi%acoucou%6s");
     return (0);
}
