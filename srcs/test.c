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
   
	//ft_printf("%-10.5s\n", "Hello World");
	//printf("%-10.5s\n", "Hello World");
	//ft_printf("salut%-10c\ncoucou%5c\ntoi", 'A', 'B');
	//printf("salut%-10c\ncoucou%5c\ntoi", 'A', 'B');
	ft_printf("%u\n", -7);
	printf("%u\n", -7);
     return (0);
}
