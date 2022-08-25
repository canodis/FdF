/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:41:47 by rtosun            #+#    #+#             */
/*   Updated: 2022/08/25 20:41:48 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_fdf
{
	int	width;
	int	height;
	int	**z_matris;
	int zoom;
	int color;
	int	shift_x;
	int	shift_y;

	void	*mlx;
	void	*window;
}	t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);
float	find_max(float a, float b);
float	find_abs(float a);
int		is_colored(int z, int z1);

#endif