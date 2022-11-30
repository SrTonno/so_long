/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_map_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:40:58 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/30 12:16:50 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	system("leaks -q so_long");
	exit(0);
}

static int	key_hook(int keycode, t_data *img)
{
	t_game	*game;

	game = &img->game;
	/*if (game->map[game->col_jp][game->fil_jp] == 'E')
		ft_close(img);*/
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
	//else if (img->game.fin == '1')
		//ft_close(img);
	//}
	/*if (img->game.fin == '1')
	{
		ft_printf("a");
		ft_close(img);
	}*/
	game->direc = keycode;
	ft_printf("fin: %d\n", game->fin);
	return (0);
}

static int	render_next_frame(t_data *img)
{
	map_to_term(img, img->game);
	return (0);
}

int	view_map(t_game game)
{
	t_data	img;
	t_photo	photo;

	game.direc = 0;
	game.num_c = 0;
	game.num_mob = 0;
	img.win_width = game.len * 50;
	img.win_height = game.count * 50;
	img.game = game;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.win_width, img.win_height, \
	"So_Long!");
	photo_to_struc(&photo, &img);
	map_to_term(&img, game);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_hook(img.win, 17, 1L << 0, ft_close, &img);
	mlx_loop(img.mlx);
	return (0);
}
