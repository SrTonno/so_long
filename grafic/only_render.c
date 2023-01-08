/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:32:46 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/08 17:24:53 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_map_back(t_data *img, t_game *game, int col, int fil)
{
	print_graf(fil * 50, col * 50, "./img/suelo50.XPM", img);
	if (game->map[col][fil] == '1')
		manage_obstacle(img, game, fil, col);
	else if (game->map[col][fil] == 'C')
		print_graf(fil * 50, col * 50, "./img/Bacon50.xpm", img);
	else if (game->map[col][fil] == 'E')
		print_graf(fil * 50, col * 50, "./img/Flag50.XPM", img);
	return ;
}

static void	render_marggin_top(t_data *img, t_game *game)
{
	int	fil;
	int	max;

	fil = -1;
	if (6 > game->len)
		max = game->len - 1;
	else
		max = 6;
	while (6 > ++fil)
	{
		print_graf(fil * 50, 0, "./img/suelo50.XPM", img);
		print_graf(fil * 50, 0, "./img/2Tree.xpm", img);
	}
}

void	only_render_jp(t_data *img, t_game *game)
{
	render_map_back(img, game, game->col_back, game->fil_back);
	render_map_back(img, game, game->col_back - 1, game->fil_back);
	render_map_back(img, game, game->col_back + 1, game->fil_back);
	render_map_back(img, game, game->col_back, game->fil_back - 1);
	render_map_back(img, game, game->col_back, game->fil_back + 1);
	render_map_back(img, game, game->col_back - 1, game->fil_back + 1);
	render_map_back(img, game, game->col_back + 1, game->fil_back - 1);
	render_map_back(img, game, game->col_back - 1, game->fil_back - 1);
	render_map_back(img, game, game->col_back + 1, game->fil_back + 1);
	if (game->col_back - 1 != 0)
		render_map_back(img, game, game->col_back - 2, game->fil_back);
	if (game->tot_c == game->num_c && game->fin == 0)
	{
		print_graf(game->fil_fin * 50, game->col_fin * 50, \
		"./img/suelo50.XPM", img);
		print_graf(game->fil_fin * 50, game->col_fin * 50, \
		"./img/GRFlag50.xpm", img);
	}
	render_marggin_top(img, game);
	direction(img, game, game->fil_jp, game->col_jp);
}
