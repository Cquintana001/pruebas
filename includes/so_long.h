/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:29:45 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/01 14:32:00 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../printf/ft_printf.h"
#include "../Libft/libft.h"
#include "../Gnl/get_next_line.h"

typedef struct s_map{
	
	  char **array;
	void *mlx;
	void *window;
	void *img;
	void *img1;
	void *img2;
	int width;
	int lenght;
	int x;
	int y;
} t_map;

int check_if_rectangular(char **map, int nbr_of_lines);
void check_first_last_line(char *line);
int check_middle_lines(char *line);
void check_walls(char **map, int nbr_of_lines);
void check_map_configuration(char **map);
int check_mandatory_char(char *array);
int check_extension(char *path, char *extension);
int check_fd(char *path);
char **check_map(int fd);
int detect_different_char(char *array);
int detect_char(char c);
int detect_empty_space(char c);
int detect_collectible(char c);
int detect_exit(char c);
int detect_starting_p(char c);
int two_dimension_array_len(char **array);
 char *map_to_one_line(int fd, char *aux1);
t_map *get_data(  char **map);
void draw_map(t_map *state);
void draw_champ(t_map *state);
#endif