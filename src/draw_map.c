/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:55:37 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/03 14:26:54 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
#include <stdio.h>

void	renew_map(t_map *state)
{
	t_image	*img;
	int		x;
	int		y;
	void	*w;

	w = state->window;
	img = state->img;
	state->x = 0;
	while (state->x < state->width)
	{
		state->y = 0;
		while (state->y < state->lenght)
		{
			x = state->x * img->w;
			y = state->y * img->h;
			if (state->array[state->x][state->y] == '1')
				mlx_put_image_to_window(state->mlx, w, img->floor, y, x);
			else
				mlx_put_image_to_window(state->mlx, w, img->path, y, x);
			state->y += 1;
		}
		state->x += 1;
	}
}

void	draw_elements(t_map *state)
{
	t_image	*img;
	int		x;
	int		y;
	void	*w;

	w = state->window;
	img = state->img;
	state->x = 0;
	while (state->x < state->width)
	{
		state->y = 0;
		while (state->y < state->lenght)
		{
			x = state->x * img->w;
			y = state->y * img->h;
			if (state->array[state->x][state->y] == 'C')
				mlx_put_image_to_window(state->mlx, w, img->collectible, y, x);
			else if (state->array[state->x][state->y] == 'E')
				mlx_put_image_to_window(state->mlx, w, img->door, y, x);
			state->y += 1;
		}
		state->x += 1;
	}
}

void	draw_map(t_map *state)
{
	t_image	*img;
	int		x;
	int		y;

	img = state->img;
	x = state->width * img->w;
	y = state->lenght * img->h;
	state->window = mlx_new_window(state->mlx, y, x, "so_long");
}
