/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:07:36 by taitomer          #+#    #+#             */
/*   Updated: 2022/09/05 16:46:36 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	legit_arg(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f'
		|| c == '%')
		return (1);
	return (0);
}

static void	init_flags(t_print *flag)
{
	flag->width = 0;
	flag->precis = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->dash = 0;
	flag->sign = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->type = '\0';
	flag->arg_length = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->is_negative = 0;
	flag->is_float = 0;
	flag->pros = 0;
}

void	print_stuff(t_print *flags)
{
	if (flags->type == 'c')
		print_char(flags);
	if (flags->type == '%')
		print_pros(flags);
	if (flags->type == 's')
		print_str(flags);
	if (flags->type == 'p')
		print_ptr(flags);
	if (flags->type == 'd' || flags->type == 'i')
		print_int(flags);
	if (flags->type == 'o')
		print_octal(flags);
	if (flags->type == 'u')
		print_u(flags);
	if (flags->type == 'x')
		print_x(flags);
	if (flags->type == 'X')
		print_capitalx(flags);
	if (flags->type == 'f')
		print_f(flags);
}

const char	*check_everything(const char *format, t_print *flags)
{
	const char	*help;
	char		*argtype;

	help = format;
	while (*format != '\0' && !legit_arg(*format))
		format++;
	if (*format == '\0')
	{
		flags->total_length += write(1, &(*help), 1);
		return (help);
	}
	check_flags(flags, help, *format);
	check_length(flags, help, *format);
	argtype = ft_strchr("cspdiouxXf%", *format);
	if (argtype)
		check_type(format, flags);
	print_stuff(flags);
	return (format);
}

int	ft_printf(const char *format, ...)
{
	t_print	flags;

	flags.total_length = 0;
	va_start(flags.ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			flags.total_length += write(1, format, 1);
		else
		{
			init_flags(&flags);
			format++;
			format = check_everything(format, &flags);
		}
		format++;
	}
	va_end(flags.ap);
	return (flags.total_length);
}
