/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:57:35 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/16 13:54:40 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
Formas de Hacer el mapa:
1.-Leer en lineas y guardarlo en listas elazadas
2.-Leer en una linea y usar el split para separar crear la array de 2 dimensiones
*/
/*
void struc_map(t_map *lst, int fd)
{
	t_map	*tmp;
	int		i;
	t_map	*p;

	//lst = (t_map *)malloc(sizeof(*lst));
	p = lst;
	while (i < 3)
	{
		tmp = (t_map *)ft_calloc(sizeof(*lst), 1);
		tmp->map = get_next_line(fd);
		//ft_printf("%s", tmp->map);
		tmp->colum = i;
		if (i == 0)
			p = tmp;
		else
		{
			p->next = tmp;
			p = p->next;
		}
		i++;
	}
	ft_printf("%d", lst->colum);
	//p = p->next;
	//ft_printf("%s", p->map);
	//lst = lst->next;
	//ft_printf("%s", lst->map);
	//lst = lst->next;

}
*/
int		count_line(char *ber)
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
	//ft_printf("%d\n", count);
	close(fd);
	return (count);
}
char	**read_map(char *ber, int count)
{
	char	**map;
	int		fd;
	char	*aux;
	int		i;

	i = 0;
	fd = open(ber, O_RDONLY);
	map = calloc(count, sizeof(char *));
	while (count > i)
	{
		aux = get_next_line(fd);
		map[i++] = ft_strtrim(aux, "\n");
		free(aux);
	}
	//ft_printf("-%s-\n", map[0]);
	if (chek_map(map, count) == 0)
	{
		liberator_map(map, count);
		perror("Error: Map not valid :(");
		exit(-1);
	}
	return (map);
}
