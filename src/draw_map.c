/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:55:37 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/03 07:54:14 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
#include <stdio.h>

 
void renew_map(t_map *state)
{
	t_image *img;

	img = state->img; 
	state->x = 0;
		while(state->x < state->width)
	{
		state->y = 0;		 
		while(state->y < state->lenght )
		{
			if(state->array[state->x][state->y] == '1')
				mlx_put_image_to_window(state->mlx, state->window, img->floor, state->y * img->h, state->x * img->w);
			else   		
				mlx_put_image_to_window(state->mlx, state->window, img->path, state->y * img->h, state->x * img->w);
			state->y+=1;
		}
		state->x+=1;
	} 
}

void draw_map(t_map *state)
{ 
	t_image *img;

	img = state->img; 
	state->window = mlx_new_window(state->mlx, state->lenght * img->h, state->width * img->w, "so_long");
	 renew_map(state);
}