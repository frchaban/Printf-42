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
    char    *cpy;
    char    *result;
    char    *stock;
    int     diff;

    cpy = ft_strdup(str);
    if (f.width && (ft_atoi(f.width) > (int)ft_strlen(cpy)))
    {
        diff = ft_atoi(f.width)- ft_strlen(cpy);
        if ( !(stock = (char *)malloc(sizeof(*stock) * (diff + 1))))
            return (NULL);
        stock[diff] = '\0';
        ft_memset(stock, 32, diff);
        cpy = (f.flag == '-' ? ft_strjoin(cpy, stock) : ft_strjoin(stock, cpy));
        /*if (f.flag == '-')
            cpy = ft_strjoin(cpy, stock);
        else
            cpy = ft_strjoin(stock, cpy);*/
    }       
    if (f.precision)
        size = ft_atoi(f.precision);
    else
        size = ft_strlen(cpy);
    result = ft_substr(cpy, 0, size);
    free(cpy);
    return(result);
}