/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:54:06 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/08 14:09:49 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
int	*hunt(char letter, char **map)
{
	int xy[2];
	int num_e;
	int	x;
	int y;

	x = -1;
	y = -1;
	num_e = 0;
	xy[0] = -1;
	xy[1] = -1;
	while (map[++x] != '/0')
	{
		while (map[x][++y] != '/0')
		{
			if (map[x][y] == 'E')
			{
				xy[0] = x;
				xy[1] = y;
				num_e++;
			}
		}
	}
	if (num_e != 1)
		return (-1);
	return(xy);
}
/*
	{
		xy[0] = -1;
		return(xy);
	}*/
