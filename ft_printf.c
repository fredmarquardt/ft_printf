/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:30:42 by fmarquar          #+#    #+#             */
/*   Updated: 2023/03/13 13:48:52 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *print, ...)
{
	int		i;
	int		p_return;
	va_list	arg;

	va_start(arg, print);
	p_return = 0;
	i = 0;
	while (print[i])
	{
		if (print[i] == '%')
		{
			p_return += (check_format(arg, print [i + 1]) - 1);
			i = i + 2;
		}
		else
			i += ft_putchar(print[i]);
	}
	va_end(arg);
	return ((p_return + i));
}

int	check_format(va_list arg, const char sign)
{
	int	arg_len;

	arg_len = 0;
	if (sign == 'c')
		arg_len += print_char(va_arg(arg, int));
	if (sign == 's')
		arg_len += print_string(va_arg(arg, char *));
	if (sign == 'i' || sign == 'd')
		arg_len += print_int(va_arg(arg, int));
	if (sign == 'x')
		arg_len += print_hex(va_arg(arg, int));
	if (sign == 'X')
		arg_len += print_large_x(va_arg(arg, int));
	if (sign == '%')
		write(1, "%", 1);
	if (sign == 'u')
		arg_len += print_uint(va_arg(arg, unsigned int));
	if (sign == 'p')
		arg_len += print_pointer(va_arg(arg, unsigned long));
	return (arg_len);
}

int	print_char(int c)
{
	int	p_return;

	p_return = 0;
	p_return += write(1, &c, 1);
	return (0);
}

int	print_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (5);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i - 1);
}

int	print_int(int c)
{
	int	i;

	ft_putnbr_fd(c, 1);
	i = 0;
	if (c == 0)
		return (0);
	if (c == -2147483648)
		return (10);
	if (c < 0)
	{
		c = c *(-1);
		i = 1;
	}
	while (c > 9)
	{
		c = c / 10;
		i++;
	}
	return (i);
}
