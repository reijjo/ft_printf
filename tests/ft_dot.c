/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:08:12 by atenhune          #+#    #+#             */
/*   Updated: 2022/06/06 15:23:13 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *str, ...);

int main(void)
{
	ft_printf("%012.2d\n", 42);
	ft_printf("% 012.4d\n", 42);
	ft_printf("% 0-12.19d\n", 42);
	ft_printf("%012.2d\n", -42);
	ft_printf("% 012.23d\n", -42);
	ft_printf("%012.9d\n", 0);
	ft_printf("%+012.0d\n", 0);
	ft_printf("%-01.21d\n", 0);
	ft_printf("%+02.5d\n", 0);
	ft_printf("%012.2d\n", INT_MAX);
	ft_printf("%+012.12d\n", INT_MAX);
	ft_printf("%+-012.14d\n", INT_MAX);
	ft_printf("%+012.9d\n", INT_MIN);
	ft_printf("%-01.2d\n", INT_MIN);
	ft_printf("%-+012.11d\n", INT_MIN);
	ft_printf("%012.2i\n", 42);
	ft_printf("% 012.2i\n", 42);
	ft_printf("%012.3i\n", -42);
	ft_printf("%0 12.13i\n", -42);
	ft_printf("%012.19i\n", 0);
	ft_printf("%+012.12i\n", 0);
	ft_printf("%-01.12i\n", 0);
	ft_printf("%+02.20i\n", 0);
	ft_printf("%012.1i\n", INT_MAX);
	ft_printf("%+012.12i\n", INT_MAX);
	ft_printf("%+-012.13i\n", INT_MAX);
	ft_printf("%+012.8i\n", INT_MIN);
	ft_printf("%-01.2i\n", INT_MIN);
	ft_printf("%-+012.21i\n", INT_MIN);
	ft_printf("%.0u\n", 0);
	ft_printf("%.u\n", 0);
	ft_printf("%.1u\n", 0);
	ft_printf("%12.11u\n", 0);
	ft_printf("%012.11u\n", 0);
	ft_printf("%02.9u\n", 0);
	ft_printf("%01.2u\n", 0);
	ft_printf("%030.7u\n", 0);
	ft_printf("%-30.13u\n", 0);
	ft_printf("%-030.32u\n", 0);
	ft_printf("%.12u\n", 123);
	ft_printf("%12.2u\n", 12345);
	ft_printf("%012.9u\n", 11);
	ft_printf("%02.21u\n", 65463456);
	ft_printf("%01.22u\n", 3456);
	ft_printf("%030.30u\n", 11324);
	ft_printf("%-30.2u\n", 1234);
	ft_printf("%-030.4u\n", 99912);
	ft_printf("%-030.x\n", 0);
	ft_printf("%#.0x\n", 0);
	ft_printf("%#.2x\n", 0);
	ft_printf("%-30.21x\n", 0);
	ft_printf("%-#30.32x\n", 0);
	ft_printf("%030.2x\n", 0);
	ft_printf("%0#30.5x\n", 0);
	ft_printf("%-030.7x\n", 123);
	ft_printf("%030.3x\n", 432134);
	ft_printf("%03.34x\n", 12312);
	ft_printf("%0#.3x\n", 12312);
	ft_printf("%-030.X\n", 0);
	ft_printf("%-30.1X\n", 0);
	ft_printf("%-#30.2X\n", 0);
	ft_printf("%030.2X\n", 0);
	ft_printf("%-030.32X\n", 123);
	ft_printf("%-0#30.2X\n", 123);
	ft_printf("%030.32X\n", 432134);
	ft_printf("%03.11X\n", 12312);
	ft_printf("%03o\n", 12312);
	ft_printf("%03o\n", 0);
	ft_printf("%#.1o\n", 0);
	ft_printf("%#.o\n", 0);
	ft_printf("%#.2o\n", 0);
	ft_printf("%#03.12o\n", 0);
	ft_printf("%#03.32o\n", 0);
	ft_printf("%0#3.4o\n", 0);
	ft_printf("%-033.11o\n", 0);
	ft_printf("%033.21o\n", 0);
	ft_printf("%03.22o\n", INT_MAX);
	ft_printf("%02.22o\n", UINT_MAX);
	ft_printf("%-030.29o\n", UINT_MAX);
	ft_printf("%-12.2o\n", UINT_MAX);
	ft_printf("%.f\n", 0.0f);
	ft_printf("%.3f\n", 0.0f);
	ft_printf("%.f\n", 1.5f);
	ft_printf("%.f\n", 1.9f);
	ft_printf("%.f\n", 1.1f);
	ft_printf("%.f\n", 0.5f);
	ft_printf("%.f\n", 9.5f);
	ft_printf("%.3f\n", 9.51234f);
	ft_printf("%.3f\n", 9.5555f);
	ft_printf("%.3f\n", 9.559999f);
	ft_printf("%.3f\n", 9.59939f);
	ft_printf("%.3f\n", 9.234234f);
	ft_printf("%.3f\n", 9.734234f);
	ft_printf("%.3f\n", 9.434234f);
	ft_printf("%.7f\n", 9.9999999999f);
	ft_printf("%.8f\n", 9.9999999999f);
	ft_printf("%.10f\n", 9.9999999999f);
	ft_printf("%.3f\n", 0.0005f);
	ft_printf("%.10f\n", 0.0005f);
	ft_printf("%.12f\n", 0.0005f);
	ft_printf("%.12f\n", 9.99999999f);
	ft_printf("%.12f\n", 0.99999999f);
	ft_printf("%.12f\n", 4.99999999f);
	ft_printf("%.14f\n", 4.99499999f);
	ft_printf("%.2f\n", 4.9999435999f);
	ft_printf("%.1f\n", 4.99999999f);
	ft_printf("%.4f\n", 4.99999999f);
	ft_printf("%.4f\n", 19.99999999f);
	ft_printf("%.20f\n", 191231232.99999999f);
	ft_printf("%.30f\n", 191231232.99999999f);
	ft_printf("%.40f\n", 191231232.99999999f);
	ft_printf("%.50f\n", 191231232.99999999f);
	ft_printf("%.f\n", -0.0f);
	ft_printf("%.2f\n", -0.0f);
	ft_printf("%.f\n", -1.5f);
	ft_printf("%.f\n", -1.9f);
	ft_printf("%.f\n", -1.1f);
	ft_printf("%.f\n", -0.5f);
	ft_printf("%.f\n", -9.5f);
	ft_printf("%.3f\n", -9.51234f);
	ft_printf("%.3f\n", -9.5555f);
	ft_printf("%.3f\n", -9.559999f);
	ft_printf("%.3f\n", -9.59939f);
	ft_printf("%.3f\n", -9.234234f);
	ft_printf("%.3f\n", -9.734234f);
	ft_printf("%.3f\n", -9.434234f);
	ft_printf("%.7f\n", -9.9999999999f);
	ft_printf("%.8f\n", -9.9999999999f);
	ft_printf("%.10f\n", -9.9999999999f);
	ft_printf("%.3f\n", -0.0005f);
	ft_printf("%.10f\n", -0.0005f);
	ft_printf("%.12f\n", -0.0005f);
	ft_printf("%.12f\n", -9.99999999f);
	ft_printf("%.12f\n", -0.99999999f);
	ft_printf("%.12f\n", -4.99999999f);
	ft_printf("%.14f\n", -4.99499999f);
	ft_printf("%.2f\n", -4.9999435999f);
	ft_printf("%.1f\n", -4.99999999f);
	ft_printf("%.4f\n", -4.99999999f);
	ft_printf("%.4f\n", -19.99999999f);
	ft_printf("%.Lf\n", 0.0l);
	ft_printf("%.3Lf\n", 0.0l);
	ft_printf("%.Lf\n", 1.5l);
	ft_printf("%.Lf\n", 1.9l);
	ft_printf("%.Lf\n", 1.1l);
	ft_printf("%.Lf\n", 0.5l);
	ft_printf("%.Lf\n", 9.5l);
	ft_printf("%.3Lf\n", 9.51234l);
	ft_printf("%.3Lf\n", 9.5555l);
	ft_printf("%.3Lf\n", 9.559999l);
	ft_printf("%.3Lf\n", 9.59939l);
	ft_printf("%.3Lf\n", 9.234234l);
	ft_printf("%.3Lf\n", 9.734234l);
	ft_printf("%.3Lf\n", 9.434234l);
	ft_printf("%.7Lf\n", 9.9999999999l);
	ft_printf("%.8Lf\n", 9.9999999999l);
	ft_printf("%.10Lf\n", 9.9999999999l);
	ft_printf("%.3Lf\n", 0.0005l);
	ft_printf("%.10Lf\n", 0.0005l);
	ft_printf("%.12Lf\n", 0.0005l);
	ft_printf("%.12Lf\n", 9.99999999l);
	ft_printf("%.12Lf\n", 0.99999999l);
	ft_printf("%.12Lf\n", 4.99999999l);
	ft_printf("%.14Lf\n", 4.99499999l);
	ft_printf("%.2Lf\n", 4.9999435999l);
	ft_printf("%.1Lf\n", 4.99999999l);
	ft_printf("%.4Lf\n", 4.99999999l);
	ft_printf("%.4Lf\n", 19.99999999l);
	ft_printf("%.20Lf\n", 191231232.99999999l);
	ft_printf("%.30Lf\n", 191231232.99999999l);
	ft_printf("%.40Lf\n", 191231232.99999999l);
	ft_printf("%.50Lf\n", 191231232.99999999l);
	ft_printf("%.Lf\n", -0.0l);
	ft_printf("%.3Lf\n", -0.0l);
	ft_printf("%.Lf\n", -1.5l);
	ft_printf("%.Lf\n", -1.9l);
	ft_printf("%.Lf\n", -1.1l);
	ft_printf("%.Lf\n", -0.5l);
	ft_printf("%.Lf\n", -9.5l);
	ft_printf("%.3Lf\n", -9.51234l);
	ft_printf("%.3Lf\n", -9.5555l);
	ft_printf("%.3Lf\n", -9.559999l);
	ft_printf("%.3Lf\n", -9.59939l);
	ft_printf("%.3Lf\n", -9.234234l);
	ft_printf("%.3Lf\n", -9.734234l);
	ft_printf("%.3Lf\n", -9.434234l);
	ft_printf("%.7Lf\n", -9.9999999999l);
	ft_printf("%.8Lf\n", -9.9999999999l);
	ft_printf("%.10Lf\n", -9.9999999999l);
	ft_printf("%.3Lf\n", -0.0005l);
	ft_printf("%.10Lf\n", -0.0005l);
	ft_printf("%.12Lf\n", -0.0005l);
	ft_printf("%.12Lf\n", -9.99999999l);
	ft_printf("%.12Lf\n", -0.99999999l);
	ft_printf("%.12Lf\n", -4.99999999l);
	ft_printf("%.14Lf\n", -4.99499999l);
	ft_printf("%.2Lf\n", -4.9999435999l);
	ft_printf("%.1Lf\n", -4.99999999l);
	ft_printf("%.4Lf\n", -4.99999999l);
	ft_printf("%.4Lf\n", -19.99999999l);
	ft_printf("%.20Lf\n", -191231232.99999999l);
	ft_printf("%.30Lf\n", -191231232.99999999l);
	ft_printf("%.40Lf\n", -191231232.99999999l);
	ft_printf("%.50Lf\n", -191231232.99999999l);
	ft_printf("%+.5f\n", 0.000001f);
	ft_printf("% .5f\n", 0.000005f);
	ft_printf("%+ .5f\n", 0.000009f);
	ft_printf("%012.f\n", 9.4f);
	ft_printf("%0-12.f\n", 9.5f);
	ft_printf("% 32.f\n", 9.9f);
	ft_printf("%+2.f\n", 99.9f);
	ft_printf("%-12.10f\n", 99.99999999999f);
	ft_printf("%+9.10f\n", 99.213981273819123f);
	ft_printf("%+9.10f\n", -99.213981273819123f);
	ft_printf("%-.10f\n", 42.73819123f);
	ft_printf("%-+1.4f\n", 42.42424242f);
	ft_printf("% -14.12f\n", 0.0005f);
	ft_printf("%-+.12f\n", 1.232323232323f);
	ft_printf("%0 14.12f\n", 8363748372381233.1239138432f);
	ft_printf("% -22.2f\n", 8363748372381233.1239138432f);
	ft_printf("%+2.3f\n", 8363748372381233.1239138432f);
	ft_printf("%-1.3f\n", 5.55500000000001f);
	ft_printf("%-19.11f\n", 0.000000000001f);
	ft_printf("%+-0 .11f\n", 0.000000000005f);
	ft_printf("% -21.11f\n", 0.000000000009f);
	ft_printf("%+101.100f\n", 0.0005f);
	ft_printf("%+101.100f\n", -0.0005f);
}