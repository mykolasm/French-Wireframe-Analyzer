/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:39:35 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/12 11:39:35 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list					*ft_lstmap(t_list *lstm, t_list *(*f)(t_list *elem))
{
	t_list *iter;
	t_list *new_one;

	if (!lstm)
	{
		return (NULL);
	}
	iter = f(lstm);
	new_one = iter;
	while (lstm->next)
	{
		lstm = lstm->next;
		if (!(iter->next = f(lstm)))
		{
			free(iter->next);
			return (NULL);
		}
		iter = iter->next;
	}
	return (new_one);
}
