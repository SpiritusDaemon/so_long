/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:02:49 by gmarques          #+#    #+#             */
/*   Updated: 2022/12/27 22:35:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft_headers/ft_printf.h"
#include "../Headers/libft_headers/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		i;
	int			n_boolean;

	i = 0;
	n_boolean = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (buffer[i])
			buffer[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = create_line(buffer, line, &n_boolean, buffer);
		if (n_boolean)
			break ;
	}
	return (line);
}

/* int	main(void)
{
	char *str;
	int fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	if (str == NULL)
		printf("(null)");
	return (0);
}  */