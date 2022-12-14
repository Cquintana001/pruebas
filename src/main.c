/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:22:44 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/05 08:28:38 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>

void	free_map(char **array)
{
	int	x;

	x = 0;
	while (array[x])
	{
		free(array[x]);
		x++;
	}
}

void	check_movements(t_map *state)
{	
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = state->pos->x;
	x1 = state->pos->x1;
	y = state->pos->y;
	y1 = state->pos->y1;
	if (x != x1 || y != y1)
	{
		state->movements += 1;
		ft_printf("Movimientos: %d\n", state->movements);
		state->pos->x1 = state->pos->x;
		state->pos->y1 = state->pos->y;
	}
}

int	close_win(void *vars1)
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
}

void	draw_champ(t_map *state)
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
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	**map;
	t_map	*state;

	if (argc != 2)
	{
		ft_printf("Error\nNumero de argumentos incorrecto\n");
		return (0);
	}
	check_extension(argv[1], ".ber");
	fd = check_fd(argv[1]);
	map = check_map(fd);
	state = get_map_data(map);
	draw_map(state);
	draw_champ(state);
	mlx_key_hook(state->window, &key_event, (void *)state);
	mlx_hook(state->window, 17, 0, &close_win, (void *)state);
	mlx_loop(state->mlx);
	return (0);
}
