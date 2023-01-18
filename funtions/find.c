/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:54:06 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/18 16:48:11 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	hunt_letter(t_game *game)
{
	int	col;
	int	fil;

	col = -1;
	while (game->count > ++col)
	{
		fil = -1;
		while (game->map[col][++fil])
		{
			if (game->map[col][fil] == 'P')
			{
				game->col_jp = col;
				game->fil_jp = fil;
			}
			else if (game->map[col][fil] == 'E')
			{
				game->col_fin = col;
				game->fil_fin = fil;
			}
		}
	}
	return ;
}

int	find_count(char letter, char **map, int count)
{
	int	num_e;
	int	col;
	int	fil;

	col = -1;
	num_e = 0;
	while (count > ++col)
	{
		fil = -1;
		while (map[col][++fil])
			if (map[col][fil] == letter)
				num_e++;
	}
	return (num_e);
}
