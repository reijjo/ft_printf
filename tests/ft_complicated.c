/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complicated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:52:53 by atenhune          #+#    #+#             */
/*   Updated: 2022/05/26 18:33:44 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *str, ...);

int main(void)
{
	ft_printf("%c %s %d\n", 97, "hei", 0);
	ft_printf("%c %s %d\n", 97, "hei", -2);
	ft_printf("%c %s %d %s\n", 97, "hei", INT_MAX, NULL);
	ft_printf("%c %s %d %i\n", 97, "hei", INT_MAX, INT_MIN);
	ft_printf("%c %s %d %s %s %d\n", 97, "hei", INT_MAX, "1", "2", 0);
	ft_printf("%c %s %d %x\n", 97, "hei", INT_MAX, 123332);
	ft_printf("%c %s %d %x %X\n", 97, "hei", INT_MAX, 123332, 0);
	ft_printf("%c %s %d %x %X %s \n", 97, "hei", INT_MAX, 123332, 12, "MOI");
	ft_printf("%c %s %d %x %d %i %X\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321);
	ft_printf("%c %s %d %x %d %i %X %s\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321 ,":)");
	ft_printf("%c %s %d %x %d %i %X %c\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, 99);
	ft_printf("%c %s %d %x %d %i %X %i\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, -123);
	ft_printf("%c %s %d %x %d %i %X %i\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, 213);
	ft_printf("%c %s %d %x %d %i %X %u\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, 123);
	ft_printf("%c %s %d %x %d %i %X %i %c\n", 97, "hei", INT_MAX, 123332, 0 , -123, 321, -0, 97);
}
