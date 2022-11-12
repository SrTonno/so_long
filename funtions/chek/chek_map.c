/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:18:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/09 18:29:24 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	unique_1(char *str)
{
	if (ft_strchr(str, '0') != 0)
		return (0);
	else
		return (1);
}

static int	first_end1(char *str, char carac)
{
	if (str[0] != 1)
	{
		ft_printf("a-%d-%s\n", (char)str[0], str);
		return (0);
	}
	ft_printf("b");
	return (1);
}

static int	chek_len(char **map)
{
	int	x;
	int	tmp;
	int len;

	x = 0;
	tmp = -1;
	len = 0;
	while (map[x + 1] != '\0')
	{
		len = ft_strlen(map[x]);
		if (x == 0)
			len++;
		//ft_printf("%d-/%s/\n", len, map[x]);
		if (tmp != -1 && tmp != len)
			return (0);
		tmp = len;
		x++;
	}
	return (1);
}

int	chek_map(char **map)
{
	int	x;
	int	output;

	x = 0;
	output = 5;
	if (chek_len(map) == 0)
		return (0);
	while (map[x + 1] != '\0')
	{
		if (x == 0 || map[x + 2] == '\0')
			output = unique_1(map[x]);
		//else
			//output = first_end1(map[x], 1);
		//ft_printf("output:%d-x:%d", output, x);
		if (output == 0)
			return (0);
		//ft_printf("\n/%s/\n", map[x]);
		x++;
	}
	return (1);
}

