/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:06:50 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/26 11:43:00 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**create_vector(int count, int len, t_game *game)
{
	char	**vector;
	int		y;
	int		x;

	y = -1;
	vector = ft_calloc(count + 1, sizeof(vector));
	while (count > ++y)
	{
		x = 0;
		vector[y] = ft_calloc(len + 1, sizeof(char));
		while (len > x)
			vector[y][x++] = '0';
	}
	vector[game->col_jp][game->fil_jp] = '1';
	return (vector);
}

static int	check_if(t_game *game, char **vector, int fil, int col)
{
	if ((vector[col][fil] != '1')
		&& (game->map[col][fil] != '1')
		&& (vector[col + 1][fil] == '1' || vector[col - 1][fil] == '1'
		|| vector[col][fil + 1] == '1' || vector[col][fil - 1] == '1'))
	{
		if (game->map[col][fil] == 'E')
			return (1);
		else
			return (2);
	}
	return (0);
}

static char	**check_path(t_game *game, int col, int fil, int mod)
{
	char	**vector;

	vector = create_vector(game->count, game->len, game);
	while (mod > 0)
	{
		mod = 0;
		col = 0;
		while (game->count - 1 > ++col)
		{
			fil = 0;
			while (game->len - 1 > ++fil)
			{
				if (check_if(game, vector, fil, col) == 1)
						vector[col][fil] = '2';
				else if (check_if(game, vector, fil, col) == 2)
				{
					mod++;
					vector[col][fil] = '1';
				}
			}
		}
	}
	return (vector);
}

static void	error_path(char **vector, t_game *game)
{
	ft_printf ("Error:\n Map not valid\n paths not available");
	liberator_map(vector, game->count);
	liberator_map(game->map, game->count);
	exit (1);
}

void	find_path(t_game *game)
{
	char	**vector;
	int		col;
	int		fil;
	int		i;

	col = 0;
	vector = check_path(game, 0, 0, 1);
	i = 0;
	while (game->count - 1 > ++col)
	{
		fil = 0;
		while (game->len - 1 > ++fil)
		{
			if (game->map[col][fil] == 'E' || game->map[col][fil] == 'C')
			{
				if (vector[col][fil] == '0')
					error_path(vector, game);
			}
		}
	}
		int a;
	a = 0;
	while (vector[a] != '\0')
		ft_printf("%s\n", vector[a++]);
	liberator_map(vector, game->count);
}
