/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:33:41 by mmarcink          #+#    #+#             */
/*   Updated: 2018/03/12 11:33:41 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*new_iter_lst;

	new_iter_lst = lst;
	while (new_iter_lst)
	{
		f(new_iter_lst);
		new_iter_lst = new_iter_lst->next;
	}
}
