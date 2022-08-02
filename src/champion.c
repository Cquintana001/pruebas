/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:25:13 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/02 15:30:49 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
int move_right(t_map *state)
{
	char **array;
	int x = state->pos->x;
	int y = state->pos->y;
	array = state->array;
	if(array[x][y+1] == '1')
		return(0); 	
	return(1);
} 
int move_left(t_map *state)
{
	char **array;
	int x = state->pos->x;
	int y = state->pos->y;
	array = state->array;
	if(array[x][y-1] == '1')
		return(0); 	
	return(1);
} 
int move_up(t_map *state)
{
	char **array;
	int x = state->pos->x;
	int y = state->pos->y;
	array = state->array;
	if(array[x+1][y] == '1')
		return(0); 	
	return(1);
} 
int move_down(t_map *state)
{
	char **array;
	int x = state->pos->x;
	int y = state->pos->y;
	array = state->array;
	if(array[x-1][y] == '1')
		return(0); 	
	return(1);
} 
int key_event(int button, void *param)
{
	t_map *state;

	state = param;
     if(button == 2 && move_right(state))
	{	 
		 state->pos->y +=1;
    	 renew_map(state);
	}
	if(button == 0 && move_left(state))
	{	 
		 state->pos->y -=1;
    	 renew_map(state);
	}
	if(button == 13 && move_down(state))
	{	 
		 state->pos->x -=1;
    	 renew_map(state);
	}
	if(button == 1 && move_up(state))
	{	 
		 state->pos->x +=1;
    	 renew_map(state);
	} 
	return (0);
}

 
void draw_champ(t_map *state)
{
	 void *pos = state;
 
	mlx_key_hook(state->window, &key_event, pos);
	 

	
}