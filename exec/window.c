/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:49:24 by bbousaad          #+#    #+#             */
/*   Updated: 2024/12/03 16:05:10 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    open_win(t_data *dta)
{
	int i = 0;
	int j = 0;
	dta->north.path = "north.xpm";
	dta->east.path = "east.xpm";
	dta->south.path = "south.xpm";
	dta->west.path = "west.xpm";
	dta->floor.path = "floor.xpm";
	dta->size = 64;
	dta->mlx = mlx_init();
	dta->win = mlx_new_window(dta->mlx, 1900, 900, "cub3d");
	//check_img(dta);
	handle_img(dta);
	put_mini(dta, i, j);
	init_spawn(dta);
	map_size(dta);
	mlx_hook(dta->win, 2, (1L << 0), key_press, dta);
	mlx_hook(dta->win, 17, (1L << 17), leave, dta);
	mlx_loop(dta->mlx);
	
}

int	leave(int key, t_data *dta)
{
	(void)key;
	ft_exit(dta, RED"RAGE QUIT !?\n"RESET, 0);
	return (0);
}
