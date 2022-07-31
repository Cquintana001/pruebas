/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exxtension.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:54:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/07/31 11:54:39 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

int check_extension(char *path, char *extension)
{
	int i;
	int j;
	int check;

	check = 1;
	j = ft_strlen(extension);
	i = ft_strlen(path);
	if(i>=j)
		while(path[i-1] && extension[j-1])
		{
			if(path[i-1] != extension[j-1])
			{
				check = 0;
				break ;
			}
			j--;
			i--;
		}
	else
		check = 0;	 
	return(check);
}