/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:28:50 by taitomer          #+#    #+#             */
/*   Updated: 2022/09/01 18:28:50 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_print *flags)
{
	char	*str;
	long	arg;

	arg = 0;
	arg = va_arg(flags->ap, long);
	length_modif(flags, &arg);
	if (arg < 0 && arg != LONG_MIN)
	{
		arg *= -1;
		flags->is_negative = 1;
	}
	str = ft_itoa_base(arg, 10);
	if (flags->dot && flags->precis == 0 && *str == '0')
	{
		free(str);
		str = NULL;
	}
	else
		flags->arg_length = ft_strlen(str);
	final_padding(flags, str, "");
	free(str);
}

void	print_u(t_print *flags)
{
	unsigned long	arg;
	char			*str;

	str = NULL;
	arg = 0;
	arg = va_arg(flags->ap, unsigned long);
	unsigned_length_modif(flags, &arg);
	str = ft_unsigned_itoa_base(arg, 10);
	if (arg < 0)
	{
		arg *= -1;
		flags->is_negative = 1;
	}
	if (flags->space || flags->sign)
	{
		flags->space = 0;
		flags->sign = 0;
	}
	if (flags->dot && flags->precis == 0 && arg == 0)
		ft_strdel(&str);
	else
		flags->arg_length = ft_strlen(str);
	final_padding(flags, str, "");
	ft_strdel(&str);
}

void	print_octal(t_print *flags)
{
	char			*str;
	char			*prefix;
	unsigned long	arg;

	prefix = NULL;
	arg = 0;
	arg = va_arg(flags->ap, unsigned long);
	unsigned_length_modif(flags, &arg);
	str = ft_unsigned_itoa_base(arg, 8);
	if ((flags->hash && !flags->dot)
		|| (flags->hash && flags->precis <= (int)ft_strlen(str)))
	{
		flags->total_length += 1;
		prefix = ft_strdup("0");
	}
	if ((!flags->hash) || (flags->hash && flags->precis))
		prefix = ft_strdup("");
	if ((flags->dot && flags->precis == 0 && *str == '0')
		|| (flags->hash && *str == '0'))
		ft_strdel(&str);
	else
		flags->arg_length += ft_strlen(str);
	final_padding(flags, str, prefix);
	free(str);
	free(prefix);
}

void	print_x(t_print *flags)
{
	unsigned long	arg;
	char			*str;
	char			*prefix;

	prefix = NULL;
	arg = 0;
	arg = va_arg(flags->ap, unsigned long);
	unsigned_length_modif(flags, &arg);
	str = ft_unsigned_itoa_base(arg, 16);
	if ((flags->hash && str && *str != '0'))
	{
		flags->total_length += 2;
		prefix = ft_strdup("0x");
	}
	if ((!flags->hash)
		|| (flags->hash && flags->precis == 0 && arg == 0)
		|| (flags->hash && flags->precis && arg == 0))
		prefix = ft_strdup("");
	if ((flags->dot && flags->precis == 0 && *str == '0'))
		ft_strdel(&str);
	else
		flags->arg_length = ft_strlen(str);
	final_padding(flags, str, prefix);
	free(str);
	free(prefix);
}

void	print_capitalx(t_print *flags)
{
	unsigned long	arg;
	char			*str;
	char			*prefix;

	prefix = NULL;
	arg = 0;
	arg = va_arg(flags->ap, unsigned long);
	unsigned_length_modif(flags, &arg);
	str = ft_str_toupper(ft_unsigned_itoa_base(arg, 16));
	if (flags->hash && str && *str != '0')
	{
		flags->total_length += 2;
		prefix = ft_strdup("0X");
	}
	if ((!flags->hash)
		|| (flags->hash && flags->precis == 0 && arg == 0)
		|| (flags->hash && flags->precis && arg == 0))
		prefix = ft_strdup("");
	if ((flags->dot && flags->precis == 0 && *str == '0'))
		ft_strdel(&str);
	else
		flags->arg_length = ft_strlen(str);
	final_padding(flags, str, prefix);
	free(str);
	free(prefix);
}
