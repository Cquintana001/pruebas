/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:52:27 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/03 09:16:39 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	detect_char(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	detect_empty_space(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

int	detect_collectible(char c)
{
	if (c == 'C')
		return (1);
	return (0);
}

int	detect_exit(char c)
{
	if (c == 'E')
		return (1);
	return (0);
}

int	detect_starting_p(char c)
{
	if (c == 'P')
		return (1);
	return (0);
}
