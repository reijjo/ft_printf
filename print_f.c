/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:53:57 by taitomer          #+#    #+#             */
/*   Updated: 2022/09/01 16:53:57 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_decimals(t_print *flags, long double arg)
{
	char	*decimals;
	int		index;

	decimals = NULL;
	index = 0;
	decimals = ft_strnew(flags->precis + 1);
	decimals[index++] = '.';
	while (index <= flags->precis)
	{
		arg *= 10;
		if ((int)arg == 0)
			decimals[index] = '0';
		else
		{
			decimals[index] = (int)arg + 48;
			arg -= (int)arg;
		}
		index += 1;
	}
	return (decimals);
}

long double	rounding(long double original, t_print *flags)
{
	long double	decider;
	long double	rounder;
	int			counter;

	decider = original;
	counter = 0;
	rounder = 0.5;
	while (++counter <= flags->precis)
		rounder /= 10;
	counter = 0;
	while (counter <= flags->precis)
	{
		decider -= (int)decider;
		decider *= 10;
		counter++;
	}
	if ((int)decider >= 5)
		return (original + rounder);
	else
		return (original);
}

double	bankers_rounding(double decimals)
{
	double	rounder;
	int		roundable;
	int		original;
	int		max_precis;

	max_precis = 16;
	original = decimals;
	roundable = (int)decimals;
	decimals -= (int)decimals;
	rounder = (decimals - (int)decimals) * 10;
	while (max_precis--)
	{
		rounder = rounder - (int)rounder;
		rounder *= 10;
		if (rounder != 0)
			break ;
	}
	if ((!ft_isodd(roundable)) || original == 0)
		return ((int)original);
	else
		return ((int)original + 1);
}

char	*join_decimals(char *str, t_print *flags, long double decimals)
{
	char	*decimals_str;
	char	*result;

	decimals_str = convert_decimals(flags, decimals);
	result = ft_strjoin(str, decimals_str);
	free(str);
	free(decimals_str);
	return (result);
}

void	print_f(t_print *flags)
{
	long double	arg;
	char		*str;

	flags->is_float = 1;
	if (!flags->dot)
		flags->precis = 6;
	arg = double_length_modif(flags);
	if (1 / arg < 0)
	{
		arg *= -1;
		flags->is_negative = 1;
	}
	if (flags->precis == 0 && arg && ((arg -(int)arg) * 10) == 5)
		arg = bankers_rounding(arg);
	arg = rounding(arg, flags);
	str = ft_itoa_base(arg, 10);
	if (flags->precis != 0 || flags->hash)
		str = join_decimals(str, flags, (arg - (long)arg));
	flags->arg_length = ft_strlen(str);
	final_padding(flags, str, "");
	ft_strdel(&str);
}
