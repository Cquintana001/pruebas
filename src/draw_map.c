/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:55:37 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/02 13:42:04 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
 
 
void draw_map(t_map *state)
{ 
	t_image *img;

	img = state->img; 
	state->window = mlx_new_window(state->mlx, state->lenght * img->h, state->width * img->w, "so_long");
	while(state->y < state->width)
	{
		state->x = 0;		 
		while(state->x < state->lenght )
		{
			if(state->array[state->y][state->x] == '1')
				mlx_put_image_to_window(state->mlx, state->window, img->floor, state->x * img->h, state->y * img->w);
			 else if (state->array[state->y][state->x] == 'P')		
				mlx_put_image_to_window(state->mlx, state->window, img->champ, state->x * img->h, state->y * img->w);   
			else   		
				mlx_put_image_to_window(state->mlx, state->window, img->path, state->x * img->h, state->y * img->w);
			state->x+=1;
		}
		state->y+=1;
	} 
}