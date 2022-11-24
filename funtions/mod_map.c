/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:01:39 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/24 16:08:49 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mod_map(int new_col, int new_fil, t_game *game)
{
	if (game->map[new_col][new_fil] == '1')
		return (game->num_mob);
	else if (game->map[new_col][new_fil] == 'C')
		game->num_c++;
	game->num_mob++;
	game->map[game->col_jp][game->fil_jp] = '0';
	game->map[new_col][new_fil] = 'P';
	game->col_jp = new_col;
	game->fil_jp = new_fil;
	ft_printf("Numero de Mobimientos -> %d\n", game->num_mob);
	ft_printf("Numero de Colecionables -> %d\n", game->num_c);
	ft_printf("------------------------------\n");
	if (game->map[new_col][new_fil] == 'E')
		exit(0);
	return (game->num_mob);
}
