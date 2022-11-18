/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:33:42 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/17 17:38:10 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>

# include "libft/index.h"
# include "struc.h"
# include <mlx.h>


char	**read_map(char *ber, int count);
int		chek_map(char **map, int count);
int		chek_arg(int argc, char **argv);
int		count_line(char *ber);
void	liberator_map(char **map, int count);
int		*hunt_letter(char letter, char **map, int count);
int		find_letter(char letter, char **map, int count);
char	**space(char **map, int count);

#endif
