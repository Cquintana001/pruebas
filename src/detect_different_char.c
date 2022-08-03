/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_different_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:01:54 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/03 09:15:28 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	detect_different_char(char *array)
{
	int	check;

	while (*array)
	{
		check = 0;
		if (*array == 'E' || *array == 'P' || *array == 'C')
			check++;
		else if (*array == '1' || *array == '0' || *array == '\n')
			check++;
		if (check == 0)
		{
			ft_printf("Hay caracteres distintos de los permitidos\n");
			return (0);
		}
		array++;
	}
	return (1);
}

char	*map_to_one_line(int fd, char *aux1)
{
	char	*line;
	char	*aux2;

	line = NULL;
	while (aux1)
	{
		if (!line)
			line = ft_strdup(aux1);
		else
		{
			aux2 = line;
			line = ft_strjoin(line, aux1);
			free(aux2);
		}
		free(aux1);
		aux1 = get_next_line(fd);
	}
	return (line);
}

int	two_dimension_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
