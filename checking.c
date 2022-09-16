/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:13:51 by taitomer          #+#    #+#             */
/*   Updated: 2022/08/31 18:13:51 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precis(const char **format, t_print *flags, char argtype)
{
	while (ft_isdigit(**format))
	{
		flags->precis = ((10 * flags->precis) + **format - 48);
		if (flags->precis < 0)
		{
			flags->dot = 0;
			break ;
		}
		(*format)++;
	}
	while (**format != argtype)
		(*format)++;
	(*format)--;
}

void	check_flags(t_print *flags, const char *format, char argtype)
{
	while (*format != argtype)
	{
		if (*format == '-')
			flags->dash = 1;
		if (*format == '0' && !flags->width && !flags->dash)
			flags->zero = 1;
		if (*format == '+')
			flags->sign = 1;
		if (*format == ' ')
			flags->space = 1;
		if (*format == '#')
			flags->hash = 1;
		if (*format == '.')
			flags->dot = 1;
		if (ft_isdigit(*format) && !flags->dot)
			flags->width = ((10 * flags->width) + *format - 48);
		else if (ft_isdigit(*format))
			check_precis(&format, flags, argtype);
		format++;
	}
	if (flags->space && flags->sign)
		flags->space = 0;
	if (flags->zero && flags->dash)
		flags->zero = 0;
}

void	check_length(t_print *flags, const char *format, char argtype)
{
	while (*format != argtype)
	{
		if (*format == 'h' && flags->h)
		{
			flags->h = 0;
			flags->hh = 1;
		}
		if (*format == 'h' && !flags->hh)
			flags->h = 1;
		if ((*format == 'l' && flags->l) || *format == 'L')
		{
			flags->l = 0;
			flags->ll = 1;
		}
		if ((*format == 'l') && !flags->ll)
			flags->l = 1;
		format++;
	}
}

void	check_type(const char *format, t_print *flags)
{
	if (ft_strchr("cspdiouxXf%", *format))
	{
		flags->type = *format;
		format++;
	}
}
