/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:33:39 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/26 12:48:58 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	convert_address_to_hex(unsigned long adr, char hex[], int *count)
{
	int		i;
	int		remainder;
	char	hex_char;

	i = 0;
	while (adr > 0)
	{
		remainder = adr % 16;
		if (remainder < 10)
			hex_char = remainder + '0';
		else
			hex_char = remainder - 10 + 'a';
		hex[i++] = hex_char;
		adr /= 16;
	}
	while (i > 0)
	{
		ft_printf_char(hex[--i]);
		(*count)++;
	}
}

int	ft_printf_ptr(void const *p)
{
	unsigned long	ptr;
	char			hex[16];
	int				count;

	ptr = (unsigned long)p;
	count = 0;
	if (ptr == 0)
	{
		ft_printf_str("(nil)");
		count += 5;
	}
	else
	{
		ft_printf_str("0x");
		count += 2;
		convert_address_to_hex(ptr, hex, &count);
	}
	return (count);
}
