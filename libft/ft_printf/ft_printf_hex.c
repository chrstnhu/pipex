/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:29 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/27 17:13:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf_hex_min(unsigned int num)
{
	int		count;
	char	*symbol;

	symbol = "0123456789abcdef";
	count = 0;
	if (num < 16)
		return (ft_printf_char(symbol[num]));
	else
	{
		count = ft_printf_hex_min(num / 16);
		count += ft_printf_hex_min(num % 16);
	}
	return (count);
}

int	ft_printf_hex_max(unsigned int num)
{
	int		count;
	char	*symbol;

	symbol = "0123456789ABCDEF";
	count = 0;
	if (num < 16)
		return (ft_printf_char(symbol[num]));
	else
	{
		count = ft_printf_hex_max(num / 16);
		count += ft_printf_hex_max(num % 16);
	}
	return (count);
}
