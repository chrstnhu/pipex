/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:24:28 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/05 11:27:03 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		set = f(lst->content);
		new = ft_lstnew(set);
		if (!new)
		{
			del(set);
			ft_lstclear(&tmp, (*del));
			return (tmp);
		}
		ft_lstadd_front(&tmp, new);
		lst = lst->next;
	}
	return (new);
}
