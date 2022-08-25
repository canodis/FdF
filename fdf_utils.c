/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:41:20 by rtosun            #+#    #+#             */
/*   Updated: 2022/08/25 20:41:21 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	find_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	find_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	is_colored(int z, int z1)
{
	if (z != 0 || z1 != 0)
		return (0xe80c0c);
	return (0xffffff);
}