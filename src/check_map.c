/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:54:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/05 08:25:35 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../includes/so_long.h"
#include <stdlib.h>

/* void	free_map(char **array)
{
	int	x;

	x = 0;
	while (array[x])
	{
		free(array[x]);
		x++;
	}
} */

int	check_if_rectangular(char **map, int nbr_of_lines)
{
	int	len_of_line;
	int	aux;
	int	i;

	i = 0;
	aux = ft_strlen(*map);
	while (i < nbr_of_lines)
	{
		len_of_line = ft_strlen(*map);
		if (len_of_line != aux || nbr_of_lines == len_of_line)
		{
			ft_printf("Error.\nEl mapa no es rectangular.\n");
			free_map(map);
			exit(0);
		}
		aux = len_of_line;
		map++;
		i++;
	}
	return (1);
}

int	check_first_last_line(char *line)
{
	int	check;

	while (*line && *line != '\n')
	{
		check = detect_char(*line);
		if (check == 0)
			return (0);
		line++;
	}
	return (1);
}

int	check_middle_lines(char *line)
{
	int	len_of_line;

	len_of_line = ft_strlen(line);
	if (*line != '1' || line[len_of_line - 1] != '1')
		return (0);
	else
		return (1);
}

void	check_walls(char **map, int nbr_of_lines)
{
	int	i;
	int	len_of_line;
	int	check;

	check = 0;
	len_of_line = ft_strlen(*map);
	i = 0;
	while (i < nbr_of_lines)
	{
		if (i == 0 || i == nbr_of_lines - 1)
			check = check_first_last_line(*map);
		else
			check = check_middle_lines(*map);
		if (check == 0)
		{	
			ft_printf("Error.\nMuros mal configurados\n");
			free_map(map);
			exit(0);
		}
		i++;
		map++;
	}
}

void	check_map_configuration(char **map)
{
	int	nbr_of_lines;

	nbr_of_lines = two_dimension_array_len(map);
	check_if_rectangular(map, nbr_of_lines);
	check_walls(map, nbr_of_lines);
}
