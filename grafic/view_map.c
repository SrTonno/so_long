/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:40:58 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/24 16:41:26 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void print_graf(int fil, int col, char *file, t_data *img)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(img->mlx, file, &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, fil, col);
	mlx_destroy_image(img->mlx, img->img);
}
/*
int	close(int keycode, t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	return (0);
}*/

static int	key_hook(int keycode, t_data *img)
{
	//int i = 0;
	t_game	*game;

	game = &img->game;
	//ft_printf("Hello from %dkey_hook!\n", keycode);
	if (keycode == 13 || keycode == 126) //w
		game->num_mob = mod_map(game->col_jp - 1, game->fil_jp, game);
	else if (keycode == 0 || keycode == 123) //a
		game->num_mob = mod_map(game->col_jp, game->fil_jp - 1, game);
	else if (keycode == 1 || keycode == 125) //s
		game->num_mob = mod_map(game->col_jp + 1, game->fil_jp, game);
	else if (keycode == 2 || keycode == 124) //d
		game->num_mob = mod_map(game->col_jp, game->fil_jp + 1, game);
	else if (keycode == 53) //ESC
		mlx_destroy_window(img->mlx, img->win);
	//while (game->count > i)
		//ft_printf("%s\n", game->map[i++]);

	return (0);
}

static void badgraund(t_data *img)
{
	int		fil;
	int 	col;

	col = 0;
	while (img->win_height > col)
	{
		fil = 0;
		while (img->win_width > fil)
		{
			print_graf(fil, col, "./img/gras_gren_50.xpm", img);
			fil += 50;
		}
	col += 50;
	}
	return ;
}

static void map_to_term(t_data *img, t_game game)
{
	int		col;
	int		fil;
	char	*num;

	col = 0;
	while (game.count > col)
	{
		fil = 0;
		while (game.len > fil)
		{
			if (game.map[col][fil] == 'P')
				//Personage
				print_graf(fil * 50, col * 50, "./img/Emoji50.xpm", img);
			else if (game.map[col][fil] == '1')
				//obstaculos
				print_graf(fil * 50, col * 50, "./img/arbusto50.xpm", img);
			else if (game.map[col][fil] == 'E')
				//obstaculos
				print_graf(fil * 50, col * 50, "./img/cruz.xpm", img);
			else if (game.map[col][fil] == 'C')
				//obstaculos
				print_graf(fil * 50, col * 50, "./img/setas.xpm", img);
			fil++;
		}
		col++;
	}
	//ft_printf("Numero de Mobimientos fuera -> %d\n", game.num_mob);
	num = ft_itoa(game.num_mob);
	mlx_string_put(img->mlx, img->win, 0, 0, 0x00FF0000, num);
	free(num);
}

static int	render_next_frame(t_data *img)
{
	badgraund(img);
	map_to_term(img, img->game);
	return (0);
}

int	view_map(t_game game)
{
	t_data	img;

	game.num_c = 0;
	game.num_mob = 0;
	img.win_width = game.len * 50;
	img.win_height = game.count * 50;
	img.game = game;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.win_width, img.win_height, "So_Long!");
	badgraund(&img);
	map_to_term(&img, game);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_loop(img.mlx);
	return (0);

}

