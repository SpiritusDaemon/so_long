/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:21 by gmarques          #+#    #+#             */
/*   Updated: 2022/12/27 22:39:09 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft_headers/ft_printf.h"
#include "../Headers/libft_headers/get_next_line.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

static int	ft_putnbr_base2(long long n, char *base, long long size)
{
	int	i;

	i = 0;
	if (n >= size || n <= -size)
		i += ft_putnbr_base2(n / size, base, size);
	n %= size;
	return (i + write(1, &base[n], 1));
}

int	ft_unsigned_base(unsigned int n, char *base, unsigned int size)
{
	int	i;

	i = 0;
	if (n >= size)
		i += ft_unsigned_base(n / size, base, size);
	n %= size;
	return (i + write(1, &base[n], 1));
}

int	ft_putnbr_base(long long n, char *base, long long size)
{
	int	i;

	i = 0;
	if (n < 0 && size != 16)
	{
		i = write(1, "-", 1);
		n *= -1;
	}
	i += ft_putnbr_base2(n, base, size);
	return (i);
}
