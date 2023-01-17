/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:39:35 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/17 19:59:59 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	t_game	game;

	i = 0;
	game.count = 0;
	if (check_arg(argc, argv) == 0)
	{
		ft_printf("Error:\n Argument not valid\n ./so_long <./map.ber>");
		return (-1);
	}
	game.count = count_line(argv[1]);
	game.map = read_map(argv[1], game);
	game.len = ft_strlen(game.map[0]);
	game.tot_c = find_count('C', game.map, game.count);
	hunt_letter(&game);
	find_path(&game);
	view_map(game);
	liberator_map(game.map, game.count);
	return (0);
}
