/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:29:45 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/03 08:25:36 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../printf/ft_printf.h"
#include "../Libft/libft.h"
#include "../Gnl/get_next_line.h"

typedef struct s_position{

	int x;
	int y;
	
} t_position;

typedef struct s_image{
	
	int w;
	int h;
	void *floor;
	void *path;
	void *champ;
} t_image;
typedef struct s_map{
	
	char **array;
	void *mlx;
	void *window;
	int width;
	int lenght;
	int x;
	int y;
	t_position *pos;
	t_image *img;
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
t_map *get_map_data(  char **map);
void draw_map(t_map *state);
void draw_champ(t_map *state);
t_image *get_image_data(t_map *map);
t_position *get_position(char **map);
int key_hook(int keycode, void *pos);
int key_event(int button, void *param);
void renew_map(t_map *state);
 int	close_win( void *vars1);
#endif