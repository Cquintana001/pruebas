/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:07:40 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/02 13:43:26 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include "../minilibx/mlx.h"


t_position *get_position(char **map)
{
	t_position *position;
	int x;
	int y;

	position = malloc(sizeof(t_position)*1);
	x = 0;
	y = 0;
	while(map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if(map[x][y] == 'P')
				{
					position->x = x;
					position->y = y;
				}
				y++;
		}
		x++;
	}
	return (position);
}

t_image *get_image_data(t_map *map)
{
	char *champ = "/Users/caquinta/Desktop/pruebas/pnj64.xpm";
	char *grass = "../grass.xpm";
	char *concrete = "../concrete.xpm";	
	t_image *img = malloc(sizeof(t_image) * 1);

	img->champ = mlx_xpm_file_to_image(map->mlx, champ, &img->w, &img->h);
	img->floor = mlx_xpm_file_to_image(map->mlx, concrete, &img->w, &img->h);
	img->path = mlx_xpm_file_to_image(map->mlx, grass, &img->w, &img->h);
	return(img);
}
t_map *get_map_data(char **map)
{
	t_map *map1 = malloc(sizeof(t_map) * 1);
	map1->array = map;
	map1->mlx = mlx_init();
	map1->lenght = ft_strlen(*map);
	map1->width = two_dimension_array_len(map);
	map1->x = 0;
	map1->y = 0;
	map1->img = get_image_data(map1);
	map1->pos = get_position(map);
	return (map1);
}