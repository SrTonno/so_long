/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:57:35 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/30 19:27:18 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_line(char *ber)
{
	char	*ptn;
	int		fd;
	int		count;

	count = 0;
	fd = open(ber, O_RDONLY);
	ptn = get_next_line(fd);
	while (ptn != NULL)
	{
		count++;
		free(ptn);
		ptn = get_next_line(fd);
	}
	free(ptn);
	close(fd);
	return (count);
}

char	**read_map(char *ber, t_game game)
{
	int		fd;
	char	*aux;
	int		i;

	i = 0;
	fd = open(ber, O_RDONLY);
	game.map = calloc(game.count, sizeof(char *));
	while (game.count > i)
	{
		aux = get_next_line(fd);
		game.map[i++] = ft_strtrim(aux, "\n");
		free(aux);
	}
	if (check_map(game) == 0)
	{
		liberator_map(game.map, game.count);
		ft_printf("Error:\n Map not valid :(");
		system("leaks -q so_long");
		exit(-1);
	}
	return (game.map);
}
