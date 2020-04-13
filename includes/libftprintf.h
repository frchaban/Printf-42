/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:34:45 by frchaban          #+#    #+#             */
/*   Updated: 2020/03/31 20:44:45 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define CONV "cspdiuxX%" 
# define FLAG "-0"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h>

unsigned int	ft_count(const char *format);
int				ft_isconv(char c);
int				ft_isflag(char c);
int				ft_printf(const char *format, ...);


typedef	struct 	s_format
{
	char		*before;
	char		flag;
	int			offsetflag;
	char		*width;
	char		*precision;
	char		conv;
	char		*result;
}				t_format;

t_format		*ft_parsing(const char *fmt);
char    		*ft_display_str(t_format f, char *str);
char    	*ft_display_int(t_format f, int arg);
char    *ft_display_mem(t_format f, long arg);
char    *ft_display_char(t_format f, char c);
char	*ft_format_width(const char *fmt, unsigned int pos);
char	*ft_format_precision(const char *fmt, unsigned int pos);
char		*ft_format_before(const char *fmt, unsigned int pos);
t_format 	ft_format_flag(t_format f, const char *fmt, unsigned int pos);
char    *ft_offset(char *width, char *tmp);
char    *ft_offset_0(char *width, char *tmp);
char    *ft_length(char *length, char *str);
char    *ft_display_d_i(t_format f, char *str);


#endif
