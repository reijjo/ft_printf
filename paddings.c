/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:52:29 by taitomer          #+#    #+#             */
/*   Updated: 2022/08/31 14:52:29 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding(int width, char c)
{
	int	i;

	i = -1;
	while (++i < width)
		write(1, &c, 1);
	return (i);
}

int	padding_count(t_print *flags, char *prefix, int precis_length)
{
	int	padding_length;
	int	prefix_length;

	padding_length = 0;
	prefix_length = ft_strlen(prefix);
	padding_length = flags->width - flags->arg_length - precis_length;
	if (flags->hash)
		padding_length -= prefix_length;
	if (flags->is_negative || flags->sign || flags->space)
		padding_length -= 1;
	if (padding_length < 0)
		padding_length = 0;
	return (padding_length);
}

int	precis_count(t_print *flags)
{
	int	precis_padding;

	precis_padding = 0;
	precis_padding = flags->precis - flags->arg_length;
	if (precis_padding < 0)
		precis_padding = 0;
	return (precis_padding);
}

void	final_padding(t_print *flags, char *arg, char *prefix)
{
	int	padding_length;
	int	precis_length;

	flags->total_length += flags->arg_length;
	precis_length = precis_count(flags);
	padding_length = padding_count(flags, prefix, precis_length);
	if ((flags->space || flags->width) && !flags->zero && !flags->dash)
		flags->total_length += padding(padding_length, ' ');
	if (flags->zero && flags->dot && padding_length >= 0 && !flags->is_float)
		flags->total_length += padding(padding_length, ' ');
	if (flags->sign || flags->is_negative || flags->space)
		put_sign(flags);
	if (flags->zero && flags->dot && flags->is_float)
		flags->total_length += padding(padding_length, '0');
	if (flags->space && flags->zero && !flags->dot)
		flags->total_length += padding(padding_length, '0');
	if (flags->hash)
		ft_putstr(prefix);
	if (flags->dot && padding_length >= 0)
		flags->total_length += padding(precis_length, '0');
	if (flags->zero && !flags->dot && !flags->space)
		flags->total_length += padding(padding_length, '0');
	ft_putstr(arg);
	if (flags->dash && padding_length >= 0)
		flags->total_length += padding(padding_length, ' ');
}
