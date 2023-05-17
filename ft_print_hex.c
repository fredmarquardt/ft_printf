/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:12:33 by fmarquar          #+#    #+#             */
/*   Updated: 2023/03/13 10:54:06 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex(unsigned int hex)
{
	int	p_return;

	p_return = 0;
	while (hex >= 16)
	{
		hex = hex / 16;
		p_return++;
	}
	return (p_return);
}

int	print_hex(unsigned int hex)
{
	int	p_return;

	p_return = count_hex(hex);
	if (hex >= 16)
	{
		print_hex(hex / 16);
		print_hex(hex % 16);
	}
	if (hex <= 9)
		ft_putchar_fd(hex + '0', 1);
	if (hex > 9 && hex < 16)
		ft_putchar_fd(hex -10 + 'a', 1);
	return (p_return);
}

int	print_large_x(unsigned int hex)
{
	int	p_return;

	p_return = count_hex(hex);
	if (hex >= 16)
	{
		print_large_x(hex / 16);
		print_large_x(hex % 16);
	}
	if (hex <= 9)
	{
		ft_putchar_fd(hex + '0', 1);
	}
	if (hex > 9 && hex < 16)
		ft_putchar_fd(hex -10 + 'A', 1);
	return (p_return);
}
