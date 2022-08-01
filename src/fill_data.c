/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:07:40 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/01 11:45:31 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include "../minilibx/mlx.h"

t_map *get_data(  char **map)
{
	t_map *map1 = malloc(sizeof(t_map) *1);
	map1->lenght = ft_strlen(*map);	  
 
	map1->width = two_dimension_array_len(map);
 
	map1->array = map;
	map1->x = 0;
	map1->y = 0;
	 
	 
	 
	return(map1);
}