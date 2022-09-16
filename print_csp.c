/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:52:43 by taitomer          #+#    #+#             */
/*   Updated: 2022/08/25 13:52:43 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_print *flags)
{
	char	c;

	c = va_arg(flags->ap, int);
	flags->total_length += 1;
	if (flags->width && !flags->dash)
		flags->total_length += padding((flags->width - 1), ' ');
	write(1, &c, 1);
	if (flags->width && flags->dash)
		flags->total_length += padding((flags->width - 1), ' ');
}

void	print_str(t_print *flags)
{
	char	*str;
	int		malloc;

	malloc = 0;
	str = va_arg(flags->ap, char *);
	if (flags->dot || !str)
	{
		if (!str && flags->precis)
			str = ft_strndup("(null)", flags->precis - 1);
		else if (!str && !flags->dot)
			str = ft_strdup("(null)");
		else if (str && flags->dot)
			str = ft_strsub(str, 0, flags->precis);
		malloc = 1;
	}
	flags->dot = 0;
	flags->precis = 0;
	flags->arg_length = ft_strlen(str);
	final_padding(flags, str, "");
	if (malloc)
		free(str);
}

void	print_ptr(t_print *flags)
{
	unsigned long	arg;
	char			*str;

	flags->hash = 1;
	flags->total_length += 2;
	arg = va_arg(flags->ap, unsigned long long);
	str = ft_unsigned_itoa_base(arg, 16);
	if (flags->dot && flags->precis == 0 && *str == '0')
		ft_strdel(&str);
	else
		flags->arg_length += ft_strlen(str);
	final_padding(flags, str, "0x");
	free(str);
}

void	print_pros(t_print *flags)
{
	flags->dot = 0;
	flags->space = 0;
	flags->arg_length += 1;
	final_padding(flags, "%", "");
}
