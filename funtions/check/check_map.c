/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:18:21 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/18 20:25:00 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	check_letter(char **map, int count)
{
	int	num[3];
	int	x;
	int	y;

	x = -1;
	num[0] = 0;
	num[1] = 0;
	num[2] = 0;
	while (count > ++x)
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'E')
				num[0]++;
			else if (map[x][y] == 'P')
				num[1]++;
			else if (map[x][y] == 'C')
				num[2]++;
		}
	}
	if (num[0] == 1 && num[1] == 1 && num[2] > 0)
		return (1);
	return (0);
}

static int	unique_1(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] != '1' && str[i] != '\0')
			return (0);
	return (1);
}

static int	first_end1(char *str, int len)
{
	int	i;

	i = 0;
	if (str[0] != '1' || str[len - 1] != '1')
		return (0);
	while (str[++i] != '\0')
	{
		if ((str[i] != '\0')
			&& (str[i] != '1' && str[i] != '0' && str[i] != 'E'
			&& str[i] != 'P' && str[i] != 'C'))
		{
				return (0);
		}
	}

	return (1);
}

static int	check_len(char **map, int count)
{
	int	x;
	int	tmp;
	int	len;

	x = 0;
	tmp = -1;
	len = 0;
	while (count > x)
	{
		len = ft_strlen(map[x]);
		if (tmp != -1 && tmp != len)
			return (0);
		tmp = len;
		x++;
	}
	return (1);
}
//int	check_caracter(char **str)
int	check_map(t_game game)
{
	int	x;
	int	output;

	x = 0;
	output = 5;
	game.len = ft_strlen(game.map[0]);
	if (game.count < 3 || game.len < 4 || game.count == game.len)
		return (0);
	if (check_len(game.map, game.count) == 0)
		return (0);
	while (game.count > x)
	{
		if (x == 0 || game.count == x + 1)
			output = unique_1(game.map[x]);
		else
			output = first_end1(game.map[x], game.len);
		if (output == 0)
			return (0);
		x++;
	}
	if (check_letter(game.map, game.count) == 0)
		return (0);
	return (1);
}
