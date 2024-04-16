/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:36 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/24 15:18:12 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf_str(char *str)
{	
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_printf_str("(null)"));
	while (str[i] != '\0')
	{
		ft_printf_char (str[i]);
		i++;
	}
	return (i);
}
