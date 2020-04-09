/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:45:56 by frchaban          #+#    #+#             */
/*   Updated: 2020/04/09 15:45:57 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_display_int(t_format f, int arg)
{
  (void)f;
  (void)arg;
  return (NULL);  
}

char    *ft_display_str(t_format f, const char *str)
{
    int     size;
    char    *result;
    char    *stock;
    int     diff;

    if (f.precision)
        size = ft_atoi(f.precision);
    else
        size = ft_strlen(str);
    result = ft_substr(str, 0, size);
    if (f.width && (ft_atoi(f.width) > (int)ft_strlen(result)))
    {
        diff = ft_atoi(f.width)- ft_strlen(result);
        if ( !(stock = (char *)malloc(sizeof(*stock) * (diff + 1))))
            return (NULL);
        stock[diff] = '\0';
        ft_memset(stock, 32, diff);
        result = (f.flag == '-' ? ft_strjoin(result, stock) : ft_strjoin(stock, result));
        free(stock);
    } 
    return(result);
}