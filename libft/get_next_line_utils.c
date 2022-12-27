/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:58:31 by gmarques          #+#    #+#             */
/*   Updated: 2022/12/27 22:34:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft_headers/ft_printf.h"
#include "../Headers/libft_headers/get_next_line.h"

static int	len_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*create_line(char *buffer, char *line, int *n_boolean,
		char *buffer_copy)
{
	char	*temp;
	int		j;

	j = 0;
	temp = malloc(((len_line(buffer) + len_line(line)) + 1) * sizeof(char));
	while (line && line[j])
	{
		temp[j] = line[j];
		j++;
	}
	while (*buffer)
	{
		if (*n_boolean)
			*buffer_copy++ = *buffer;
		else
			temp[j++] = *buffer;
		*n_boolean += (*buffer == '\n');
		*buffer++ = 0;
	}
	temp[j] = '\0';
	free(line);
	return (temp);
}
