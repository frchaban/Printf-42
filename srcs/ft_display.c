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

char    *ft_offset_0(char *width, char *tmp)
{
    char    *offset;
    int     diff;

    if (width && (ft_atoi(width) > (int)ft_strlen(tmp)))
    {
        diff = ft_atoi(width)- ft_strlen(tmp);
        if ( !(offset = (char *)malloc(sizeof(*offset) * (diff + 1))))
            return (NULL);
        offset[diff] = '\0';
        ft_memset(offset, 48, diff);
        return (offset);
    } 
    return (NULL);
}


char    *ft_display_char(t_format f, char c)
{
    char    *result;
    char    *offset;

    if (!(result = (char *)malloc(sizeof(*result)* 2)))
        return (NULL);
    result[0] = c;
    result[1] = '\0';
    if ((offset = ft_offset(f.width, result)))
    {
        result = (f.flag == '-' ? ft_strjoin(result, offset) : ft_strjoin(offset, result));
        free(offset);
    }   
  return (result);
}

char    *ft_length(char *length, char *str)
{
    char    *offset;
    char    *result;

    if (str[0] == '-')
        result = ft_substr(str, 1, ft_strlen(str) - 1);
    else 
        result = ft_substr(str, 0, ft_strlen(str));
    if ((offset = ft_offset_0(length, result)))
    {
        result = ft_strjoin(offset, result);
        free(offset);
    }
    if (str[0] == '-')
        result = ft_strjoin("-", result);
    free (length);
    free (str);
    return (result);
}

char    *ft_display_d_i(t_format f, char *str)
{
    char   *result;
    char    *offset;

    if (f.precision && ft_atoi(f.precision) == 0)  
        if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "-0") == 0)
            return (result = ft_strdup(""));
    result = ft_length(f.precision, str);
    if (!f.precision && f.flag == '0')
        result = ft_length(ft_itoa(ft_atoi(f.width)), result);
    else if  ((offset = ft_offset(f.width, result)))
    {
        result = (f.flag == '-' ? ft_strjoin(result, offset) : ft_strjoin(offset, result));
        free(offset);
    }
    return(result);
}


char    *ft_display_int(t_format f, int arg)
{
    if (f.conv =='c')
        return (ft_display_char(f, (char)arg));
    else if (f.conv == 'd' || f.conv == 'i')
        return (ft_display_d_i(f, ft_itoa(arg)));
    else if (f.conv == 'u')
        return (ft_display_d_i(f, ft_itoa_us(arg + 1 + 4294967295)));
    else if (f.conv == 'x' || f.conv == 'X')
        return (ft_display_d_i(f, ft_uhex(arg + 1 + 4294967295, f.conv)));
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