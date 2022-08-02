/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:25:13 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/02 13:28:07 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
#include <stdio.h>

int key_event(int button, void *param)
{
	param =NULL;
    // Whenever the event is triggered, print the value of button to console.
    printf("evento %d\n",button);
	return (0);
}

 
void draw_champ(t_map *state, t_position *pos)
{
	int x;
	int y;

	x = 0;
	y = 1;
 
	mlx_key_hook(state->window, &key_event, (void*)pos);
	 

	
}