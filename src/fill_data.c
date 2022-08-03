/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:07:40 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/03 14:58:28 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include "../minilibx/mlx.h"

t_position	*get_position(char **map)
{
	t_position	*position;
	int			x;
	int			y;

	position = malloc(sizeof(t_position) * 1);
	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				position->y = y;
				position->x = x;
			}
			y++;
		}
		x++;
	}
	return (position);
}

int	get_coins(char **map)
{
	int			x;
	int			y;
	int			coins;

	coins = 0;
	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				coins++;
			y++;
		}
		x++;
	}
	return (coins);
}

t_image	*get_image_data(t_map *map)
{	
	t_image		*img;
	t_elements	i;

	img = malloc(sizeof(t_image) * 1);
	i.ch = "img/pnj64.xpm";
	i.p = "img/grass.xpm";
	i.f = "img/concrete.xpm";
	i.co = "img/collectible.xpm";
	i.d = "img/door.xpm";
	img->champ = mlx_xpm_file_to_image(map->mlx, i.ch, &img->w, &img->h);
	img->floor = mlx_xpm_file_to_image(map->mlx, i.f, &img->w, &img->h);
	img->path = mlx_xpm_file_to_image(map->mlx, i.p, &img->w, &img->h);
	img->collectible = mlx_xpm_file_to_image(map->mlx, i.co, &img->w, &img->h);
	img->door = mlx_xpm_file_to_image(map->mlx, i.d, &img->w, &img->h);
	return (img);
}

t_map	*get_map_data(char **map)
{
	t_map	*map1;

	map1 = malloc(sizeof(t_map) * 1);
	map1->array = map;
	map1->mlx = mlx_init();
	map1->lenght = ft_strlen(*map);
	map1->width = two_dimension_array_len(map);
	map1->x = 0;
	map1->y = 0;
	map1->img = get_image_data(map1);
	map1->pos = get_position(map);
	map1->coins = get_coins(map);
	map1->movements = 0;
	map1->pos->x1 = map1->pos->x;
	map1->pos->y1 = map1->pos->y;
	return (map1);
}
