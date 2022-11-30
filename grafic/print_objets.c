/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:18:20 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/30 16:02:49 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_graf(int fil, int col, char *file, t_data *img)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(img->mlx, file, &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, fil, col);
	mlx_destroy_image(img->mlx, img->img);
}

void	direction(t_data *img, t_game *game, int fil, int col)
{
	if (game->direc == 13 || game->direc == 126) //w
		print_graf(fil * 50, col * 50, "./img/Pig_Up50.XPM", img);
	else if (game->direc == 0 || game->direc == 123) //a
		print_graf(fil * 50, col * 50, "./img/Pig_Left50.XPM", img);
	else if (game->direc == 2 || game->direc == 124) //d
		print_graf(fil * 50, col * 50, "./img/Pig_Right50_1.xpm", img);
	else //s default
	{
		if (game->direc != 1 && game->direc != 125)
			print_graf(fil * 50, (col - 1) * 50, "./img/duda50.XPM", img);
		print_graf(fil * 50, col * 50, "./img/Pig_Down50.xpm", img);
	}
	if (game->status == 1)
		print_graf(fil * 50, (col - 1) * 50, "./img/Starving50.xpm", img);
}

void	manage_obstacle(t_data *img, t_game *game, int fil, int col)
{
	if (fil == 0 || fil == game->len - 1)
		print_graf(fil * 50, col * 50, "./img/Tree50.xpm", img);
	else if (col == 0 || col == game->count - 1)
		print_graf(fil * 50, col * 50, "./img/Tree50.xpm", img);
	else if ((col + fil) % 3 == 0)
		print_graf(fil * 50, col * 50, "./img/Boulders50.XPM", img);
	else if ((col + fil) % 3 == 1)
		print_graf(fil * 50, col * 50, "./img/Bush50.XPM", img);
		//print_graf(fil * 50, col * 50, "./img/Tree50.XPM", img);
	else if ((col + fil) % 3 == 2)
		print_graf(fil * 50, col * 50, "./img/Box50.XPM", img);
}

void	str_put(t_data *img, t_game game)
{
	char	*num;

	num = ft_itoa(game.num_mob);
	mlx_string_put(img->mlx, img->win, 0, 0, 0x00FF0000, num);
	free(num);
	if (game.fin == 1)
		mlx_string_put(img->mlx, img->win, 50, 0, 0x00FF0000, \
		"Para finalizar pulse p");
}
