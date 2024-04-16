/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:45:17 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/04 15:16:58 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf_arg(char type, va_list args)
{
	int	i;

	i = 0;
	if (type == 'c')
		i += ft_printf_char(va_arg(args, int));
	else if (type == 's')
		i += ft_printf_str(va_arg(args, char *));
	else if (type == 'p')
		i += ft_printf_ptr(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		i += ft_printf_dec(va_arg(args, int));
	else if (type == 'u')
		i += ft_printf_dec_uns(va_arg(args, unsigned int));
	else if (type == 'x')
		i += ft_printf_hex_min(va_arg(args, unsigned int));
	else if (type == 'X')
		i += ft_printf_hex_max(va_arg(args, unsigned int));
	else if (type == '%')
		i += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_printf_arg(s[i + 1], args);
			i++;
		}
		else
			count += ft_printf_char(s[i]);
		i++;
	}
	va_end (args);
	return (count);
}
