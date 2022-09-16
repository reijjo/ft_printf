/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:34:13 by taitomer          #+#    #+#             */
/*   Updated: 2021/11/27 17:10:28 by taitomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*help;

	if (lst == NULL)
		return (NULL);
	fresh = (t_list *)malloc(sizeof(t_list));
	if (fresh == NULL)
		return (NULL);
	fresh = f(lst);
	help = fresh;
	while (lst->next)
	{
		fresh->next = (t_list *)malloc(sizeof(t_list));
		if (fresh->next == NULL)
			return (NULL);
		fresh->next = f(lst->next);
		fresh = fresh->next;
		lst = lst->next;
	}
	fresh->next = NULL;
	return (help);
}
