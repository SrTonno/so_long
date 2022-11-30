/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:18:20 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/28 15:11:26 by tvillare         ###   ########.fr       */
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
	t_photo *photo;
	photo = &game->photo;


	//ft_printf("fin: %d\n", game->direc);
	if (game->direc == 13 || game->direc == 126) //w
		//print_graf(fil * 50, col * 50, "./img/Pig_Up50.XPM", img);
		mlx_put_image_to_window(img->mlx, img->win, photo->jp[0], 50 * fil, 50 * col);
	else if (game->direc == 0 || game->direc == 123) //a
		//print_graf(fil * 50, col * 50, "./img/Pig_Left50.XPM", img);
		mlx_put_image_to_window(img->mlx, img->win, photo->jp[1], 50 * fil, 50 * col);
	else if (game->direc == 2 || game->direc == 124) //d
		//print_graf(fil * 50, col * 50, "./img/Pig_Right50_1.xpm", img);
		mlx_put_image_to_window(img->mlx, img->win, photo->jp[2], 50 * fil, 50 * col);
	else //s default
	{
		if (game->direc != 1 && game->direc != 125)
			print_graf(fil * 50, (col - 1) * 50, "./img/duda50.XPM", img);
		//print_graf(fil * 50, col * 50, "./img/Pig_Down50.xpm", img);
		mlx_put_image_to_window(img->mlx, img->win, photo->jp[3], 50 * fil, 50 * col);
	}
	//if(game->fin == 1)
		//mlx_string_put(img->mlx, img->win, 10, 10, 0x00FF0000, "Para finalizar");
}

void	manage_obstacle(t_data *img, t_game *game, int fil, int col)
{
	//ft_printf("modulo %d\n", (col + fil) % 2);
	if (fil == 0 || col == 0 || fil == game->len - 1 || col == game->count - 1)
	{
		print_graf(fil * 50, col * 50, "./img/Tree50.XPM", img);
	}
	else if ((col + fil) % 3 == 0)
		print_graf(fil * 50, col * 50, "./img/Boulders50.XPM", img);
	else if ((col + fil) % 3 == 1)
		print_graf(fil * 50, col * 50, "./img/Bush50.XPM", img);
	else if ((col + fil) % 3 == 2)
		print_graf(fil * 50, col * 50, "./img/Ruby50.XPM", img);
}
