/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:22:44 by caquinta          #+#    #+#             */
/*   Updated: 2022/07/31 11:34:34 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../minilibx/mlx.h"

int main()
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "/Users/caquinta/Desktop/nuevofolder/magic.xpm";
	int		img_width;
	int		img_height;
	int x = 0;
	int y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 640, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	while(y<640)
	{
		x = 0;
		while(x<640)
			{
				mlx_put_image_to_window(mlx, mlx_win, img, x, y);
				x+=img_width;
			}
			y+=img_height;
	}
	mlx_loop(mlx);
}