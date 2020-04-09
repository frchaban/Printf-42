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

char    *ft_offset(char *width, char *tmp)
{
    char    *offset;
    int     diff;

    if (width && (ft_atoi(width) > (int)ft_strlen(tmp)))
    {
        diff = ft_atoi(width)- ft_strlen(tmp);
        if ( !(offset = (char *)malloc(sizeof(*offset) * (diff + 1))))
            return (NULL);
        offset[diff] = '\0';
        ft_memset(offset, 32, diff);
        return (offset);
    } 
    return (NULL);
}

char    *ft_display_char(t_format f, char c)
{
    (void)f;
  (void)c;
  return (NULL);
}

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
    char    *offset;

    size = (f.precision ? ft_atoi(f.precision) : ft_strlen(str));
    result = ft_substr(str, 0, size);
    if ((offset = ft_offset(f.width, result)))
    {
         result = (f.flag == '-' ? ft_strjoin(result, offset) : ft_strjoin(offset, result));
        free(offset);
    }
    return(result);
}