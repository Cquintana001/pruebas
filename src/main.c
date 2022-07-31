/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:22:44 by caquinta          #+#    #+#             */
/*   Updated: 2022/07/31 13:35:34 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../minilibx/mlx.h"
#include "../includes/state.h"
#include "../printf/ft_printf.h"
int	main(int argc, char *argv[])
{
	int fd;
	/* t_map	state;
	 

	if (!init_state(&state))
		exit(0); */
	if(argc !=2)
	{
		ft_printf("Numero de argumentos incorrecto\n");
		return(0);
	}
	 check_extension(argv[1], ".ber");
	fd = check_fd(argv[1]); 	 
	check_map(fd);
	
	return (0);
}