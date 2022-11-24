/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:46 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/24 16:36:11 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_game {
	int		col_jp;
	int		fil_jp;
	char	**map;
	int		count;
	int		len;
	int		num_mob;
	int		num_c;
}				t_game;

typedef struct	s_data {
	void	*img;
	void	*win;
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	t_game	game;
}				t_data;

