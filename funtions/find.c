/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:54:06 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/19 11:37:39 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*hunt_letter(char letter, char **map, int count)
{
	int *xy;
	int num_e;
	int	x;
	int y;

	xy = ft_calloc(3, sizeof(int));
	x = -1;
	num_e = 0;
	xy[0] = -1;
	xy[1] = -1;
	while (count > ++x)
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == letter)
			{
				xy[0] = x;
				xy[1] = y;
				num_e++;
			}
		}
	}
	return (xy);
}
/*
int	find_count(char letter, char **map, int count)
{

	int num_e;
	int	x;
	int y;

	x = -1;
	num_e = 0;
	while (count > ++x)
	{
		y = -1;
		while (map[x][++y])
			if (map[x][y] == letter)
				num_e++;
	}
	ft_printf("num_%c:%d\n", letter, num_e);
	return (num_e);
}
*/
