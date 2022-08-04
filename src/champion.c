/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:25:13 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/04 11:57:33 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
#include <stdio.h>

int	move_right(t_map *state)
{
	char	**array;
	int		x;
	int		y;

	x = state->pos->x;
	y = state->pos->y;
	array = state->array;
	if (array[x][y + 1] == '1')
		return (0);
	else if (array[x][y + 1] == 'C')
	{
		array[x][y + 1] = '0';
		state->coins -= 1;
	}
	else if (array[x][y + 1] == 'E' && state->coins < 1)
		close_win((void *)state);
	state->pos->y += 1;
	return (1);
}

int	move_left(t_map *state)
{
	char	**array;
	int		x;
	int		y;
	int		c;

	c = state->coins;
	x = state->pos->x;
	y = state->pos->y;
	array = state->array;
	if (array[x][y - 1] == '1')
		return (0);
	else if (array[x][y - 1] == 'C')
	{
		array[x][y - 1] = '0';
		state->coins -= 1;
	}
	else if (array[x][y - 1] == 'E' && state->coins < 1)
		close_win((void *)state);
	state->pos->y -= 1;
	return (1);
}

int	move_up(t_map *state)
{
	char	**array;
	int		x;
	int		y;
	int		c;

	c = state->coins;
	x = state->pos->x;
	y = state->pos->y;
	array = state->array;
	if (array[x + 1][y] == '1')
		return (0);
	else if (array[x + 1][y] == 'C')
	{
		array[x + 1][y] = '0';
		state->coins -= 1;
	}
	else if (array[x + 1][y] == 'E' && state->coins < 1)
		close_win((void *)state);
	state->pos->x += 1;
	return (1);
}

int	move_down(t_map *state)
{
	char	**array;
	int		x;
	int		y;
	int		c;

	c = state->coins;
	x = state->pos->x;
	y = state->pos->y;
	array = state->array;
	if (array[x - 1][y] == '1')
		return (0);
	else if (array[x - 1][y] == 'C')
	{
		state->coins -= 1;
		array[x - 1][y] = '0';
	}
	else if (array[x - 1][y] == 'E' && state->coins < 1)
		close_win((void *)state);
	state->pos->x -= 1;
	return (1);
}

int	key_event(int button, void *param)
{
	t_map	*state;

	state = param;
	if (button == 2 && move_right(state))
		draw_champ(state);
	if (button == 0 && move_left(state))
		draw_champ(state);
	if (button == 13 && move_down(state))
		draw_champ(state);
	if (button == 1 && move_up(state))
		draw_champ(state);
	if (button == 53)
		close_win(state);
	check_movements(state);
	return (0);
}

/* void	draw_champ(t_map *state)
{
	t_image	*img;
	int		x;
	int		y;

	img = state->img;
	x = state->pos->x * img->w;
	y = state->pos->y * img->h;
	renew_map(state);
	draw_elements(state);
	mlx_put_image_to_window(state->mlx, state->window, img->champ, y, x);
}  */
/* int	close_win(void *vars1)
{
	t_map	*vars;
	int		i;

	vars = vars1;
	i = 0;
	while ((vars->array)[i])
	{
		free((vars->array)[i]);
		i++;
	}
	free(vars->array);
	free(vars->pos);
	free(vars->img);
	exit(0);
	return (0);
} */