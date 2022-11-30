/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:12:44 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/28 14:39:12 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void photos_jp(t_photo *photo, t_data *img)
{
	int		img_width;
	int		img_height;

	photo->jp[0] = mlx_xpm_file_to_image(img->mlx, "./img/Pig_Up50.XPM", &img_width, &img_height);
	photo->jp[1] = mlx_xpm_file_to_image(img->mlx, "./img/Pig_Left50.XPM", &img_width, &img_height);
	photo->jp[2] = mlx_xpm_file_to_image(img->mlx, "./img/Pig_Right50_1.xpm", &img_width, &img_height);
	photo->jp[3] = mlx_xpm_file_to_image(img->mlx, "./img/Pig_Down50.xpm", &img_width, &img_height);

}

static void photos_obj(t_photo *photo, t_data *img)
{
	int		img_width;
	int		img_height;

	photo->obj[0] = mlx_xpm_file_to_image(img->mlx, "./img/Tree50.XPM", &img_width, &img_height);
	photo->obj[1] = mlx_xpm_file_to_image(img->mlx, "./img/Boulders50.XPM", &img_width, &img_height);
	photo->obj[2] = mlx_xpm_file_to_image(img->mlx, "./img/Bush50.XPM", &img_width, &img_height);
	photo->obj[3] = mlx_xpm_file_to_image(img->mlx, "./img/Box50.XPM", &img_width, &img_height);
}

static void photos_miscellany(t_photo *photo, t_data *img)
{
	int		img_width;
	int		img_height;

	photo->emotion = mlx_xpm_file_to_image(img->mlx, "./img/duda50.XPM", &img_width, &img_height);
	photo->fload = mlx_xpm_file_to_image(img->mlx, "./img/suelo50.XPM", &img_width, &img_height);
	photo->fin = mlx_xpm_file_to_image(img->mlx, "./img/Flag50.XPM", &img_width, &img_height);
	photo->colec = mlx_xpm_file_to_image(img->mlx, "./img/Flag50.XPM", &img_width, &img_height);
}

void	photo_to_struc(t_photo *photo, t_data *img)
{
	photos_jp(photo, img);
	photos_obj(photo, img);
	photos_miscellany(photo, img);
}
