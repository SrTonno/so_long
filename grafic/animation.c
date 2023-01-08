/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:11:31 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/13 11:47:40 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
static put_fload(int col, int fil, int new_col, int new_fil)
void	animation(int col, int fil, char mode, t_data *img)
{
	if (mode == 'w') //w
		print_graf(fil * 50, col * 50, "./img/Pig_Up50.XPM", img);
	else if (mode == 'a') //a
		print_graf(fil * 50, col * 50, "./img/Pig_Left50.XPM", img);
	else if (mode == 'd') //d
		print_graf(fil * 50, col * 50, "./img/Pig_Right50_1.xpm", img);
	else if //s default
	{
		print_graf(fil * 50, col * 50, "./img/Pig_Down50.xpm", img);
	}
}
