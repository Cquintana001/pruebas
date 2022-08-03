/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:22:44 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/03 09:06:19 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
#include "../includes/state.h"
#include "../printf/ft_printf.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	**map;
	t_map	*state;

	if (argc != 2)
	{
		ft_printf("Numero de argumentos incorrecto\n");
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
