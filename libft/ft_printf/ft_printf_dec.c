/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:30:25 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/24 15:17:35 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf_dec(int num)
{
	int		count;
	char	*symbol;

	symbol = "0123456789ABCDEF";
	count = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
	}
	else if (num < 0)
	{
		count += ft_printf_char('-');
		count += ft_printf_dec((num * -1));
	}
	else if (num < 10)
		count += ft_printf_char(symbol[num]);
	else
	{
		count += ft_printf_dec(num / 10);
		count += ft_printf_dec(num % 10);
	}
	return (count);
}

int	ft_printf_dec_uns(unsigned int num)
{
	unsigned int	count;
	char			*symbol;

	symbol = "0123456789ABCDEF";
	count = 0;
	if (num < 10)
		count += ft_printf_char(symbol[num]);
	else
	{
		count += ft_printf_dec(num / 10);
		count += ft_printf_dec(num % 10);
	}
	return (count);
}
