/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:06:50 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/17 16:40:15 by tvillare         ###   ########.fr       */
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
char	**space(char **map, int count)
{
	int		len;
	int		col;
	int		 fil;
	int		mod;
	char	**vector;

	mod = 1;
	col = 0;
	len = ft_strlen(map[0]);
	vector = create_vector(count, len);
	//ft_printf("(%s)", vector[0]);
	while (mod > 0)
	{
		mod = 0;
		ft_printf("\nmod\n");
		while (count - 1> ++col)
		{
			fil = 0;
			ft_printf("col");
			while (len - 1 > ++fil)
			{
				if (map[col][fil] == 'E')
				{
					ft_printf("e");
					mod++;
					vector[col][fil] = '1';
				}
				else if ((map[col][fil] != '1')
					&& (vector[col + 1][fil] == '1' || vector[col - 1][fil] == '1'
					|| vector[col][fil + 1] == '1' || vector[col][fil - 1] == '1'))
				{
					ft_printf("v");
					mod++;
					vector[col][fil] = '1';
				}
			//ft_printf("%c", vector[col][fil + 1]);
			}
			ft_printf("\n");
		}
		ft_printf("\n?%d?", mod);
		ft_printf("\n");
	}
	return (vector);
}
