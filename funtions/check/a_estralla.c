/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_estralla.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:50:45 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/30 11:55:20 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	score(int col_org, int fil_org, t_game game)
{
	int	col;
	int	fil;

	col = col_org - game.col_fin;
	fil = fil_org - game.fil_fin;
	if (col < 0)
		col = col * - 1;
	if (fil < 0)
		fil = fil * - 1;
	return (col + fil);
}

static void	new_link(t_star *star, int col, int fil)
{
	t_star tmp;

	tmp.col = col;
	tmp.fil = fil;
	if (star->next != NULL)
		star = start->next;
	star->next = tmp;
}

static int	find_wall(t_game game, int col, int fil)
{
	t_star star;
	int	winer;
	int	punto;
	int	col;
	int	fil;
	int	col_winer;
	int	fil_winer;


}

int	a_estrella(t_game game)
{
	int	col;
	int	fil;
	int	check;

	check = 0;
	col = 0;
	while (game.count - 1 > ++col)
	{
		fil = 0;
		while (game.map[col][++fil - 1])
		{
			if (game.map[col][fil] != '0' && game->map[col][fil] != '1')
			{
				check = find_wall(game, col, fil);
				if (check == -1)
					return (0);
			}
		}
	}
	return (1);
}
