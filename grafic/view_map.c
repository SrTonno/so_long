/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:40:58 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/08 17:26:21 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_to_term(t_data *img, t_game game)
{
	int		col;
	int		fil;

	col = -1;
	while (game.count > ++col)
	{
		fil = -1;
		while (game.len > ++fil)
		{
			print_graf(fil * 50, col * 50, "./img/suelo50.XPM", img);
			if (game.map[col][fil] == 'P')
				direction(img, &game, fil, col);
			else if (game.map[col][fil] == '1')
				manage_obstacle(img, &game, fil, col);
			else if (game.map[col][fil] == 'E')
			{
			//if (game->tot_c != game->num_c)
				print_graf(fil * 50, col * 50, "./img/Flag50.XPM", img);
			//else
				//print_graf(fil * 50, col * 50, "./img/salida_abierta.xpm", img);
			}
			else if (game.map[col][fil] == 'C')
				print_graf(fil * 50, col * 50, "./img/Bacon50.xpm", img);
		}
	}
}

static void	defauld_vaue(t_game *game)
{
	game->col_back = game->col_jp;
	game->fil_back = game->fil_jp;
	game->direc = 0;
	game->num_c = 0;
	game->num_mob = 0;
	game->fin = 0;
	game->status = 1;
}

int	view_map(t_game game)
{
	t_data	img;
	//t_photo	photo;

	defauld_vaue(&game);
	img.win_width = game.len * 50;
	img.win_height = game.count * 50;
	img.game = game;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.win_width, img.win_height, \
	"So_Long!");
	ft_printf("Game status:\n");
	ft_printf("-------------------------------\n");
	ft_status(&game);
	//photo_to_struc(&photo, &img);
	//game.photo = photo;
	map_to_term(&img, game);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_hook(img.win, 17, 1L << 0, ft_close, &img);
	mlx_loop(img.mlx);
	return (0);
}
