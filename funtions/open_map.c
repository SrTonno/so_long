/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:57:35 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/09 18:48:18 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strjoin2(char *s1, char *s2)
{
	int		x1;
	int		x2;
	int		i;
	int		j;
	char	*pnt;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x1 = ft_strlen((char *)s1);
	x2 = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	pnt = malloc(sizeof(char) * (x1 + x2 + 1));
	if (pnt == NULL)
		return (NULL);
	while (s1[j] != '\0')
		pnt[i++] = (char)s1[j++];
	j = 0;
	while (s2[j] != '\0')
		pnt[i++] = (char)s2[j++];
	pnt[i] = '\0';
	free(s1);
	return (pnt);
}
/*
Formas de Hacer el mapa:
1.-Leer en lineas y guardarlo en listas elazadas
2.-Leer en una linea y usar el split para separar crear la array de 2 dimensiones
*/
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
void	read_map()
{
	char	*ptn;
	char	**map;
	int		fd;
	t_map	*lst;
	int		numbytes;
	char	tmp;

	ptn = ft_calloc(1, sizeof(char));
	fd = open("map.ber", O_RDONLY);

	numbytes = 1;
	while (numbytes > 0)
	{
		numbytes = read(fd, tmp, 1);
		if (numbytes == -1)
			return ;
		ptn = ft_strjoin2(ptn, tmp);
	}

	map = ft_split(ptn, '\n');
	free(ptn);

	ft_printf("%s\n", map[0]);
	ft_printf("%s\n", map[1]);
	ft_printf("%s\n-----\n", map[2]);
	//chek_map(map);
	ft_printf("%d\n", chek_map(map));

}
/*
int main()
{
	read_map();
	return 0;
}
*/
