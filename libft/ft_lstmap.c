/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:15:53 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/31 20:41:43 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin;

	begin = NULL;
	if (lst && f)
	{
		new = f(lst);
		begin = new;
		lst = lst->next;
		while (lst && f)
		{
			new->next = f(lst);
			new = new->next;
			lst = lst->next;
		}
	}
	return (begin);
}
