/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:58:46 by fmarquar          #+#    #+#             */
/*   Updated: 2023/03/13 13:52:26 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_uint(unsigned int n, int fd)
{
	if (n > 9)
		ft_put_uint(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
	return ;
}

int	print_uint(unsigned int c)
{
	int	i;

	ft_put_uint(c, 1);
	i = 0;
	if (c == 0)
		return (0);
	while (c > 9)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

int	print_pointer(unsigned long ptr)
{
	int	p_return;

	p_return = 0;
	write (1, "0x", 2);
	if (ptr == 0)
		write (1, "0", 1);
	else
	{
		print_ptr(ptr);
		p_return += count_ptr(ptr);
	}
	return (2 + p_return);
}

int	count_ptr(uintptr_t ptr)
{
	int	p_return;

	p_return = 0;
	while (ptr >= 16)
	{
		ptr = ptr / 16;
		p_return++;
	}
	return (p_return);
}

int	print_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		print_ptr(ptr / 16);
		print_ptr(ptr % 16);
	}
	if (ptr <= 9)
		ft_putchar_fd(ptr + '0', 1);
	if (ptr > 9 && ptr < 16)
		ft_putchar_fd(ptr -10 + 'a', 1);
	return (0);
}
