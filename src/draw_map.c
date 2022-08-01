/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:55:37 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/01 14:52:12 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
 
 
void draw_map(t_map *state)
{
	int img_width;
	int img_height;
	 
	state->mlx = mlx_init();
	state->img = mlx_xpm_file_to_image(state->mlx, "/Users/caquinta/Desktop/pruebas/concrete.xpm", &img_width, &img_height);
	state->img1 = mlx_xpm_file_to_image(state->mlx, "/Users/caquinta/Desktop/pruebas/grass.xpm", &img_width, &img_height);
	state->img2 =  mlx_xpm_file_to_image(state->mlx,  "/Users/caquinta/Desktop/pruebas/output-onlinepngtools.xpm", &img_width, &img_height);
	state->window = mlx_new_window(state->mlx, state->lenght * img_height, state->width * img_width, "so_long");
	while(state->y < state->width)
	{
		state->x = 0;		 
		while(state->x < state->lenght )
		{
			if(state->array[state->y][state->x] == '1')
				mlx_put_image_to_window(state->mlx, state->window, state->img, state->x * img_height, state->y * img_width);
			else if (state->array[state->y][state->x] != '0')		
				mlx_put_image_to_window(state->mlx, state->window, state->img1, state->x * img_height, state->y * img_width); 
			state->x+=1;
		}
		state->y+=1;
	} 
}