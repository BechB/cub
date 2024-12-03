/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:12:38 by bbousaad          #+#    #+#             */
/*   Updated: 2024/12/02 15:22:40 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_mini(t_data *dta, int i, int j)
{
	int	x;
	int	y;
	int size;

	size = 7;
	x = 0;
	y = 0;
	while(dta->map[y])
	{
		x = 0;
		i = 0;
		while(dta->map[y][x])
		{
			if(dta->map[y][x] == '1')
			{
				draw_big_pixel(dta->mlx, dta->win, i, j, size, PURPLE2);
				i = i + size;
			}
			else if(dta->map[y][x] == '0')
			{
				draw_big_pixel(dta->mlx, dta->win, i, j, size, GREY2);
				i = i + size;
			}
			else if(dta->map[y][x] == 'N' || dta->map[y][x] == 'E' || 
					dta->map[y][x] == 'S' || dta->map[y][x] == 'W')
			{
				draw_big_pixel(dta->mlx, dta->win, i, j, size, GREY2);
				draw_big_pixel(dta->mlx, dta->win, i, j, size - 3, RED2);
				i = i + size;
			}
			else
				i = i + size;
			x++;
		}
		y++;
		j = j + size;
	}
}
