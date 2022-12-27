/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:06:35 by gmarques          #+#    #+#             */
/*   Updated: 2022/12/27 22:40:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr_base(long long n, char *base, long long size);
int				receive_ptr(unsigned long long n);
int				ft_unsigned_base(unsigned int n, char *base, unsigned int size);
int				print_base_hex(unsigned long long n, char *base, unsigned long long size);

#endif
