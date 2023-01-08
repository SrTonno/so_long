/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:46 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/08 17:11:13 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H
# include "so_long.h"
/*
typedef struct s_photo
{
	void	*jp[5];
	void	*emotion;
	void	*fload;
	void	*obj[5];
	void	*fin;
	void	*colec;
}				t_photo;*/

typedef struct s_game
{
	int		col_jp;
	int		fil_jp;
	int		col_fin;
	int		fil_fin;
	char	**map;
	int		count;
	int		len;
	int		num_mob;
	int		num_c;
	int		fin;
	int		direc;
	int		tot_c;
	int		col_back;
	int		fil_back;
	int		status;
}	t_game;

typedef struct s_data
{
	void	*img;
	void	*win;
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	int		move;
	t_game	game;
}				t_data;

#endif
