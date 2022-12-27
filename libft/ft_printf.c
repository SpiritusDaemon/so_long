/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:51 by gmarques          #+#    #+#             */
/*   Updated: 2022/12/27 22:38:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft_headers/ft_printf.h"
#include "../Headers/libft_headers/get_next_line.h"

int	ft_cases(va_list arg, char *str, int i)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (str[i] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (str[i] == 'p')
		return (receive_ptr(va_arg(arg, long long)));
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_base(va_arg(arg, long long), "0123456789", 10));
	if (str[i] == 'u')
		return (ft_unsigned_base(va_arg(arg, unsigned int), "0123456789", 10));
	if (str[i] == 'x')
		return (ft_putnbr_base(va_arg(arg, unsigned int)
				, "0123456789abcdef", 16));
	if (str[i] == 'X')
		return (ft_putnbr_base(va_arg(arg, unsigned int)
				, "0123456789ABCDEF", 16));
	if (str[i] == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		size;

	i = -1;
	size = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%' && ++i)
			size += ft_cases(arg, (char *)str, i);
		else
			size += ft_putchar(str[i]);
	}
	return (size);
}

/* int main(void)
{
	printf("%i: ", ft_printf("\nmy func = %d\n", -1));
	printf("\n%i: ", printf("\nmy func = %d\n", -1));
	return (0);
} */
