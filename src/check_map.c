/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:54:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/03 09:04:02 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../includes/so_long.h"

int	check_if_rectangular(char **map, int nbr_of_lines)
{
	int	len_of_line;
	int	aux;
	int	i;

	i = 0;
	aux = ft_strlen(*map);
	ft_printf("aux %d\n", nbr_of_lines);
	while (i < nbr_of_lines)
	{
		len_of_line = ft_strlen(*map);
		ft_printf("len_of_line %d\n", len_of_line);
		if (len_of_line != aux || nbr_of_lines == len_of_line)
			return (0);
		aux = len_of_line;
		map++;
		i++;
	}
	ft_printf("ES RECTANGULAR\n");
	return (1);
}

void	check_first_last_line(char *line)
{
	int	check;

	while (*line && *line != '\n')
	{
		check = detect_char(*line);
		if (check == 0)
		{
			ft_printf("Muros primera y última línea mal configurados\n");
			exit(0);
		}
		line++;
	}
}

int	check_middle_lines(char *line)
{
	int	len_of_line;

	len_of_line = ft_strlen(line);
	if (*line != '1' || line[len_of_line - 1] != '1')
	{
		ft_printf("Muros líneas intermedias mal configurados\n");
		return (0);
	}
	else
		return (1);
}

void	check_walls(char **map, int nbr_of_lines)
{
	int	i;
	int	len_of_line;

	len_of_line = ft_strlen(*map);
	i = 0;
	while (i < nbr_of_lines)
	{
		if (i == 0 || i == nbr_of_lines - 1)
			check_first_last_line(*map);
		else
			check_middle_lines(*map);
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
