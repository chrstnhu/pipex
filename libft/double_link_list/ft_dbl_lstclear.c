/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:49:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/01/15 13:59:47 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_dbl_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
