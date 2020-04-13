/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 13:51:59 by frchaban          #+#    #+#             */
/*   Updated: 2020/04/13 13:52:01 by frchaban         ###   ########.fr       */
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

char    *ft_length(char *length, char *str)
{
    char    *offset;
    char    *result;

    if (str[0] == '-')
        result = ft_substr(str, 1, ft_strlen(str) - 1);
    else 
        result = ft_substr(str, 0, ft_strlen(str));
    if ((offset = ft_offset_0(length, result)))
        result = ft_strjoin_freed(offset, result);
    if (str[0] == '-')
        result = ft_strjoin_freed(ft_strdup("-"), result);
    free(str);
    return (result);
}