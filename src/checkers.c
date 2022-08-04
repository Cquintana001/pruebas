/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:03:00 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/04 09:47:00 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "../includes/so_long.h"
#include "../Libft/libft.h"
#include "../Gnl/get_next_line.h"

int	check_mandatory_char(char *array)
{
	int	collectible;
	int	exit;
	int	start_p;
	int	empty_space;

	empty_space = 0;
	collectible = 0;
	exit = 0;
	start_p = 0;
	while (*array)
	{
		collectible += detect_collectible(*array);
		exit += detect_exit(*array);
		start_p += detect_starting_p(*array);
		empty_space += detect_empty_space(*array);
		array++;
	}
	if (collectible < 1 || exit < 1 || start_p < 1 || empty_space < 1)
	{
		ft_printf("There is no exit, collectible, start_p or empty space.\n");
		return (0);
	}
	return (1);
}

int	check_extension(char *path, char *extension)
{
	int	i;
	int	j;
	int	check;

	check = 1;
	j = ft_strlen(extension);
	i = ft_strlen(path);
	if (i >= j)
	{
		while (path[i - 1] && extension[j - 1])
		{
			if (path[i - 1] != extension[j - 1])
			{
				check = 0;
				break ;
			}
			j--;
			i--;
		}
	}
	else
		check = 0;
	return (check);
}

int	check_fd(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("El path no es una dirección válida\n ");
		return (0);
	}
	else
		return (fd);
}

char	**check_map(int fd)
{
	char	*line;
	char	*aux1;
	char	**map;

	aux1 = get_next_line(fd);
	if (!aux1)
	{
		//free(aux1);
		ft_printf("Error.\nEl mapa está vacío.\n");
		exit(0);
	}
	else
		line = map_to_one_line(fd, aux1);
	if (!check_mandatory_char(line) || !detect_different_char(line))
	{
		free(line);
		exit(0);
	}
	map = ft_split(line, '\n');
	free(line);
	check_map_configuration(map);
 
	return (map);
}
