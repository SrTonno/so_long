/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:46:54 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/15 19:40:21 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	liberator_map(char **map, int count)
{
	int	i;

	i = 0;
	while (count > i)
		free(map[i++]);
	free(map);
}
