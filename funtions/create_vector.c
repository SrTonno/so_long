/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:06:50 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/08 14:06:06 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

static char	**create_vector(int count, int len)
{
	char	**vector;
	int		y;
	int		x;

	y = -1;
	vector = ft_calloc(count + 1, sizeof(vector));
	while (count >  ++y)
	{
		x = 0;
		vector[y] = ft_calloc(len + 1, sizeof(char));
		while (len > x)
			vector[y][x++] = '0';
	}
	return (vector);
}
//else if ((map[col][fil] != '1') && (vector[col + 1][fil] == '1' || vector[col - 1][fil] == '1' vector[col][fil + 1] == '1' || vector[col][fil - 1] == '1'))
char	**check_path(t_game *game)
{
	int		col;
	int		 fil;
	int		mod;
	char	**vector;
	int		i;

	mod = 1;
	vector = create_vector(game->count, game->len);
	vector[game->col_jp][game->fil_jp] = '1';
	while (mod > 0)
	{
		mod = 0;
		col = 0;
		while (game->count - 1 > ++col)
		{
			fil = 0;
			while (game->len - 1 > ++fil)
			{
				if ((vector[col][fil] != '1')
					&& (game->map[col][fil] != '1')
					&& (vector[col + 1][fil] == '1' || vector[col - 1][fil] == '1'
					|| vector[col][fil + 1] == '1' || vector[col][fil - 1] == '1'))
				{
					if (game->map[col][fil] == 'E')
						vector[col][fil] = '2';
					else
					{
						mod++;
						vector[col][fil] = '1';
					}
				}
			}
		}
	}
	i = 0;
	while (game->count > i)
		ft_printf("%s\n", vector[i++]);
	return (vector);
}


void	find_path(t_game *game)
{
	char	**vector;
	int		col;
	int		fil;
	int		i;

	col = 0;
	vector = check_path(game);
	i = 0;
	//while (game->count > i)
		//ft_printf("%s\n", vector[i++]);
	while (game->count - 1> ++col)
	{
		fil = 0;
		while (game->len - 1 > ++fil)
		{
			//ft_printf("%c", game->map[col][fil]);
			if (game->map[col][fil] == 'E' || game->map[col][fil] == 'C')
			{
				//ft_printf("%c", game->map[col][fil]);
				if (vector[col][fil] == '0')
				{
					ft_printf ("Error\n Caminos no validos");
					exit (1);
				}
			}
		}
	}
	liberator_map(vector, game->count);

}
