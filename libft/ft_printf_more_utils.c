/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_more_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:17:06 by gmarques          #+#    #+#             */
/*   Updated: 2022/12/27 22:40:00 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft_headers/ft_printf.h"
#include "../Headers/libft_headers/get_next_line.h"

int	receive_ptr(unsigned long long n)
{
	int	i;

	if (n == 0)
		return (write(1, "(nil)", 5));
	i = write(1, "0x", 2);
	i += print_base_hex(n, "0123456789abcdef", 16);
	return (i);
}

int	print_base_hex(unsigned long long n, char *base, unsigned long long size)
{
	int	i;

	i = 0;
	if (n >= size)
		i += print_base_hex(n / size, base, size);
	n %= size;
	return (i + write(1, &base[n], 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		str = "(null)";
	while (str[++i])
		;
	return (write(1, str, i));
}
