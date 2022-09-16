/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:57:26 by taitomer          #+#    #+#             */
/*   Updated: 2022/08/31 19:57:26 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_modif(t_print *flags, long *number_ptr)
{
	if (flags->h)
		*number_ptr = (short)*number_ptr;
	else if (flags->hh)
		*number_ptr = (char)*number_ptr;
	else if (flags->l)
		*number_ptr = (long)*number_ptr;
	else if (flags->ll)
		*number_ptr = (long long)*number_ptr;
	else
		*number_ptr = (int)*number_ptr;
}

void	unsigned_length_modif(t_print *flags, unsigned long *number_ptr)
{
	if (flags->h)
		*number_ptr = (unsigned short)*number_ptr;
	else if (flags->hh)
		*number_ptr = (unsigned char)*number_ptr;
	else if (flags->l)
		*number_ptr = (unsigned long)*number_ptr;
	else if (flags->ll)
		*number_ptr = (unsigned long long)*number_ptr;
	else
		*number_ptr = (unsigned int)*number_ptr;
}

long double	double_length_modif(t_print *flags)
{
	if (flags->l)
		return (va_arg(flags->ap, double));
	else if (flags->ll)
		return (va_arg(flags->ap, long double));
	else
		return (va_arg(flags->ap, double));
}
