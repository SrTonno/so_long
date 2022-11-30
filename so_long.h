/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:33:42 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/30 12:24:24 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/union_libft.h"
# include "struc.h"

char	**read_map(char *ber, t_game game);
int		check_map(t_game game);
int		check_arg(int argc, char **argv);
int		count_line(char *ber);
void	liberator_map(char **map, int count);
void	hunt_letter(t_game *game);
int		find_count(char letter, char **map, int count);
char	**space(char **map, int count);
int		mod_map(int new_col, int new_fil, t_game *game);

//grafic
int		view_map(t_game game);
void	direction(t_data *img, t_game *game, int fil, int col);
void	print_graf(int fil, int col, char *file, t_data *img);
void	manage_obstacle(t_data *img, t_game *game, int fil, int col);
void	str_put(t_data *img, t_game game);
void	only_render_jp(t_data *img, t_game *game);
int		render_next_frame(t_data *img);
int		key_hook(int keycode, t_data *img);
int		ft_close(t_data *img);

//void	photo_to_struc(t_photo *photo, t_data *img);

//int	close(int keycode, t_data *img);

#endif
