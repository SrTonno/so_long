/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:54:06 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/24 12:08:03 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	hunt_letter(char letter, t_game *game)
{
	int	col;
	int fil;

	col = -1;
	while (game->count > ++col)
	{
		fil = -1;
		while (game->map[col][++fil])
		{
			if (game->map[col][fil] == letter)
			{
				game->col_jp = col;
				game->fil_jp = fil;
				return ;
			}
		}
	}
	return ;
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
