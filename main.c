/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:39:35 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/24 12:28:10 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int		i;
	t_game	game;

	i = 0;
	game.count = 0;
	if (chek_arg(argc, argv) == 0)
	{
		//strerror(2);
		perror("Error: argument not valid");
		//ft_printf( "strerror says open failed: %s\n", strerror(4) );
		return (-1);
	}
	game.count = count_line(argv[1]);
	game.map = read_map(argv[1], game);
	game.len = ft_strlen(game.map[0]);

	i = 0;
	//while (game.count > i)
		//ft_printf("%s\n", game.map[i++]);
	hunt_letter('P', &game);
	view_map(game);
	system("leaks -q so_long");
	return (0);
}
