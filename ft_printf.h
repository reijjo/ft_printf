/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:10:10 by taitomer          #+#    #+#             */
/*   Updated: 2022/09/02 18:18:39 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_print
{
	va_list	ap;
	int		width;
	int		precis;
	int		zero;
	int		dot;
	int		dash;
	int		total_length;
	int		arg_length;
	int		sign;
	int		space;
	int		hash;
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		is_negative;
	int		is_float;
	int		pros;
	char	type;
}	t_print;

int			ft_printf(const char *format, ...);

int			padding(int width, char c);
int			padding_count(t_print *flags, char *prefix, int precis_length);
int			precis_count(t_print *flags);
void		final_padding(t_print *flags, char *arg, char *prefix);

void		check_precis(const char **format, t_print *flags, char argtype);
void		check_flags(t_print *flags, const char *format, char argtype);
void		check_length(t_print *flags, const char *format, char argtype);
void		check_type(const char *format, t_print *flags);

void		print_char(t_print *flags);
void		print_str(t_print *flags);
void		print_ptr(t_print *flags);
void		print_int(t_print *flags);
void		print_octal(t_print *flags);
void		print_u(t_print *flags);
void		print_x(t_print *flags);
void		print_capitalx(t_print *flags);
void		print_f(t_print *flags);
void		print_pros(t_print *flags);

void		put_sign(t_print *flags);

char		*ft_strrev(char *str);
int			ft_digit_count(unsigned long n, int base);
char		*ft_unsigned_itoa_base(unsigned long dec, int base);
char		*ft_itoa_base(long dec, int base);
char		*ft_str_toupper(char *string);
int			ft_isodd(int number);

void		length_modif(t_print *flags, long *number_ptr);
void		unsigned_length_modif(t_print *flags, unsigned long *number_ptr);
long double	double_length_modif(t_print *flags);

#endif
