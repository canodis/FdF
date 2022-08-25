/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:03:33 by rtosun            #+#    #+#             */
/*   Updated: 2022/08/25 20:41:26 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdbool.h>
#include <math.h>

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int z;
	int z1;

	z = data->z_matris[(int)y][(int)x];
	z1 = data->z_matris[(int)y1][(int)x1];
	// -------- Yakinlasmaz ------- //
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	// --------- Renklendirme işlemleri ---------- //
	data->color = is_colored(z, z1);
	// ---------  3D  ---------- //
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	// ----------Objeyi kaydirma islemi------------- //
	x += data->shift_x;
	x1 += data->shift_x;
	y += data->shift_y;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = find_max(find_abs(x_step), find_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx, data->window, x , y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}