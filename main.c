/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:03:36 by rtosun            #+#    #+#             */
/*   Updated: 2022/08/25 20:32:27 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_events(int key, t_fdf *data)
{
	if (key == 53)
		exit(1);
	if (key == 2)
		data->shift_x += 10;
	if (key == 0)
		data->shift_x -= 10;
	if (key == 1)
		data->shift_y += 10;
	if (key == 13)
		data->shift_y -= 10;
	if (key == 4)
	{
		if (data->zoom >= 20)
			data->zoom += 20;
		else
			data->zoom++;
	}
	if (key == 38)
	{
		if (data->zoom > 20)
			data->zoom -= 20;
		else if (data->zoom > 1)
			data->zoom--;
	}
	mlx_clear_window(data->mlx, data->window);
	draw(data);
}

int	main(int ac, char **av)
{
	// hareket tuslari wasd
	// yakinlas uzaklas : h - j
	if (ac != 2)
	{
		printf("Bad args !");
		exit(1);
	}
	t_fdf	*data;
	data = malloc(sizeof(t_fdf));
	data->shift_x = 200;
	data->shift_y = 200;
	read_file(av[1], data);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1000, 1000, "FdF");
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->window, key_events, data);
	mlx_loop(data->mlx);
}