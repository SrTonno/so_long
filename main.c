/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:39:35 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/18 20:10:21 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**map;
	int		i;
	int		count;
	//int		*xy;
//	char	**vector;

	i = 0;
	count = 0;
	if (chek_arg(argc, argv) == 0)
	{
		//strerror(2);
		perror("Error: argument not valid");
		//ft_printf( "strerror says open failed: %s\n", strerror(4) );
		return (-1);
	}
	count = count_line(argv[1]);
	map = read_map(argv[1], count);
	//xy = hunt_letter('P', map, count);
	//vector = space(map, count);
	/*while(count > i)
	{
		ft_printf("%d->/%s/\n", ft_strlen(map[i]), map[i]);
		i++;
	}*/
	//printf("%d-%d", xy[0], xy[1]);
	//liberator_map(map, count);
	//free(xy);
	//ft_printf("\nfin\n");
	//system("leaks -q so_long");
	return (0);
}
