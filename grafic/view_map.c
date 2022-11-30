/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:40:58 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/30 12:31:57 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
int	ft_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	system("leaks -q so_long");
	ft_printf("\nEnd the game");
	exit(0);
}

static int	key_hook(int keycode, t_data *img)
{
	t_game	*game;

	game = &img->game;
	if (keycode == 13 || keycode == 126) //w
		game->num_mob = mod_map(game->col_jp - 1, game->fil_jp, game);
	else if (keycode == 0 || keycode == 123) //a
		game->num_mob = mod_map(game->col_jp, game->fil_jp - 1, game);
	else if (keycode == 1 || keycode == 125) //s
		game->num_mob = mod_map(game->col_jp + 1, game->fil_jp, game);
	else if (keycode == 2 || keycode == 124) //d
		game->num_mob = mod_map(game->col_jp, game->fil_jp + 1, game);
	else if (keycode == 53 || game->fin == 1) //ESC
		ft_close(img);
	game->direc = keycode;
	img->game = *game;
	return (0);
}

static int	render_next_frame(t_data *img)
{
	only_render_jp(img, &img->game);
	print_graf(0, 0, "./img/Tree50.XPM", img);
	str_put(img, img->game);
	return (0);
}*/

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
				print_graf(fil * 50, col * 50, "./img/Flag50.XPM", img);
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
	ft_printf("col_fin/%d/", game.col_fin);
	//photo_to_struc(&photo, &img);
	//game.photo = photo;
	map_to_term(&img, game);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_hook(img.win, 17, 1L << 0, ft_close, &img);
	mlx_loop(img.mlx);
	return (0);
}
