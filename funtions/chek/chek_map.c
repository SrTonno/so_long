/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:18:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/19 11:43:41 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	check_letter(char **map, int count)
{

	int num_e;
	int num_p;
	int num_c;
	int	x;
	int y;

	x = -1;
	num_e = 0;
	num_p = 0;
	num_c = 0;
	while (count > ++x)
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'E')
				num_e++;
			else if (map[x][y] == 'P')
				num_p++;
			else if (map[x][y] == 'C')
				num_c++;
		}
	}
	if (num_e == 1 && num_p == 1 && num_c > 0)
		return (1);
	return (0);
}

static int	unique_1(char *str)
{
	if (ft_strchr(str, '0') != 0)
	{
		return (0);
	}
	else
		return (1);
}

static int	first_end1(char *str, int len)
{
	if (str[0] != '1' || str[len - 1] != '1')
		return (0);
	return (1);
}

static int	chek_len(char **map, int count)
{
	int	x;
	int	tmp;
	int	len;

	x = 0;
	tmp = -1;
	len = 0;
	while (count > x)
	{
		//ft_printf("%x", x);
		len = ft_strlen(map[x]);
		//ft_printf("%d-%s\n", len, map[x]);
		if (tmp != -1 && tmp != len)
			return (0);
		tmp = len;
		x++;
	}
	return (1);
}

int	chek_map(char **map, int count)
{
	int	x;
	int	output;
	int len;

	x = 0;
	output = 5;
	len = ft_strlen(map[0]);
	if (count < 3 ||len < 4 || count == len)
		return (0);
	if (chek_len(map, count) == 0)
		return (0);
	while (count > x)
	{
		if (x == 0 || count == x + 1)
			output = unique_1(map[x]);
		else
			output = first_end1(map[x], len);
		if (output == 0)
			return (0);
		x++;
	}
	if (check_letter(map, count) == 0)
		return(0);
	return (1);
}
