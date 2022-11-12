/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:33:42 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/11 18:37:42 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "utils/libft/libft.h"
# include "utils/printf/ft_printf.h"
# include "utils/get_next_line/get_next_line.h"
# include "struc.h"

char	*ft_strjoin2(char *s1, char *s2);
void	read_map();
int		chek_map(char **map);
int		chek_arg(int argc, char **argv);

#endif
