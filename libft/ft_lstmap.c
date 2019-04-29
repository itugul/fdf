/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:25:42 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/25 15:09:31 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *check;

	if (!lst)
		return (NULL);
	new = f(lst);
	check = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(check->next = f(lst)))
		{
			while (new->next)
			{
				check = new->next;
				free(check);
			}
			return (NULL);
		}
		check = check->next;
	}
	return (new);
}
