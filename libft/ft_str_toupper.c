/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:32:50 by taitomer          #+#    #+#             */
/*   Updated: 2022/09/01 18:32:50 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *string)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_strnew(ft_strlen(string));
	while (string[i])
	{
		if (string[i] >= 97 && string[i] <= 122)
			result[i] = (string[i] - 32);
		else
			result[i] = string[i];
		i++;
	}
	ft_strdel(&string);
	return (result);
}
