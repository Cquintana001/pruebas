/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:25:13 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/01 14:41:17 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"

void draw_champ(t_map *state)
{
	int x;
	int y;

	x = 1;
	y = 1;
	
	mlx_put_image_to_window(state->mlx, state->window, state->img2, state->x * 64, state->y * 64);

	
}