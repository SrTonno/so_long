/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:33:42 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/24 16:31:43 by tvillare         ###   ########.fr       */
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


char	**read_map(char *ber, t_game game);
int		chek_map(t_game game);
int		chek_arg(int argc, char **argv);
int		count_line(char *ber);
void	liberator_map(char **map, int count);
void	hunt_letter(char letter, t_game *game);
//int		find_count(char letter, char **map, int count);
char	**space(char **map, int count);
int		mod_map(int new_col, int new_fil, t_game *game);


//grafic
int		view_map(t_game game);
//int	close(int keycode, t_data *img);


#endif
