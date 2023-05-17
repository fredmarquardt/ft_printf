/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:57:50 by fmarquar          #+#    #+#             */
/*   Updated: 2023/03/13 13:48:36 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *print, ...);
int		print_char(int c);
int		check_format(va_list arg, const char sign);
int		print_string(char *str);
int		print_int(int c);

int		print_hex(unsigned int hex);
int		print_large_x(unsigned int hex);

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_putchar(char c);

void	ft_put_uint(unsigned int n, int fd);
int		print_uint(unsigned int c);
int		print_pointer(unsigned long ptr);
int		print_ptr(uintptr_t ptr);
int		count_ptr(uintptr_t ptr);

size_t	ft_strlen(const char *str);

#endif