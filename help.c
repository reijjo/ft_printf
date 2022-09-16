/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:27:31 by taitomer          #+#    #+#             */
/*   Updated: 2022/08/31 18:27:31 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	char	*rev_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	rev_str = ft_strnew(i);
	while (--i >= 0)
		rev_str[j++] = str[i];
	return (rev_str);
}

int	ft_digit_count(unsigned long n, int base)
{
	unsigned long	temp;
	int				i;

	i = 0;
	temp = n;
	while (temp != 0 && i++ != -1)
		temp = temp / base;
	return (i);
}

char	*ft_unsigned_itoa_base(unsigned long dec, int base)
{
	char	*str;
	int		remain;
	int		i;
	char	*temp;

	if (dec == 0)
		return (ft_strdup("0"));
	str = ft_strnew(ft_digit_count(dec, base));
	i = 0;
	remain = 0;
	while (dec != 0)
	{
		remain = dec % base;
		if (remain < 10)
			str[i] = remain + 48;
		else
			str[i] = remain + 87;
		dec = dec / base;
		i++;
	}
	temp = ft_strrev(str);
	free(str);
	return (temp);
}

void	put_sign(t_print *flags)
{
	if (flags->is_negative)
		flags->total_length += write(1, "-", 1);
	else if (flags->space)
		flags->total_length += write(1, " ", 1);
	else
		flags->total_length += write(1, "+", 1);
	flags->width -= 1;
}

char	*ft_itoa_base(long dec, int base)
{
	char	*str;
	int		remain;
	int		i;
	char	*temp;

	if (dec == 0)
		return (ft_strdup("0"));
	if (dec == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	str = ft_strnew(ft_digit_count(dec, base));
	i = 0;
	remain = 0;
	while (dec != 0)
	{
		remain = dec % base;
		if (remain < 10)
			str[i] = remain + 48;
		else
			str[i] = remain + 87;
		dec = dec / base;
		i++;
	}
	temp = ft_strrev(str);
	free(str);
	return (temp);
}
