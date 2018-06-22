/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:06:12 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/22 09:06:12 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *f_elem;
	t_list *prev_f_elem;
	t_list *first;

	prev_f_elem = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		f_elem = f(lst);
		if (!prev_f_elem)
		{
			prev_f_elem = f_elem;
			first = f_elem;
		}
		else
		{
			prev_f_elem->next = f_elem;
			prev_f_elem = f_elem;
		}
		lst = lst->next;
	}
	return (first);
}
