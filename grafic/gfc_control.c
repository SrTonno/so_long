/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfc_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:31:03 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/17 16:59:01 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	ft_printf("\nEnd the game");
	exit(0);
}

int	key_hook(int keycode, t_data *img)
{
	t_game	*game;

	game = &img->game;
	if (keycode == 13 || keycode == 126)
		game->num_mob = mod_map(game->col_jp - 1, game->fil_jp, game);
	else if (keycode == 0 || keycode == 123)
		game->num_mob = mod_map(game->col_jp, game->fil_jp - 1, game);
	else if (keycode == 1 || keycode == 125)
		game->num_mob = mod_map(game->col_jp + 1, game->fil_jp, game);
	else if (keycode == 2 || keycode == 124)
		game->num_mob = mod_map(game->col_jp, game->fil_jp + 1, game);
	else if (keycode == 53 || game->fin == 1)
		ft_close(img);
	game->direc = keycode;
	img->game = *game;
	return (0);
}

int	render_next_frame(t_data *img)
{
	only_render_jp(img, &img->game);
	str_put(img, img->game);
	return (0);
}
