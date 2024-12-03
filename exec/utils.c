/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:04:01 by bbousaad          #+#    #+#             */
/*   Updated: 2024/12/03 17:50:24 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_data *dta, char *mess, int status)
{
	printf("%s\n", mess);
	exit (status);
	(void)dta;
}

void	draw_big_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void ft_draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
    int step;
    int x;
    int y;
    int i;
    int delta_x;
    int delta_y;
    
    delta_x = x2 - x1;
    delta_y = y2 - y1;
    if (abs(delta_x) >= abs(delta_y))
        step = abs(delta_x);
    else
        step = abs(delta_y);
    delta_x = delta_x / step;
    delta_y = delta_y / step;
    x = x1;
    y = x2;
    i = 0;
    while (i < step)
    {
        mlx_pixel_put(data->mlx, data->win, x, y, color);
        x += delta_x;
        y += delta_y;
        i++;
    }
}

void draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    
    while (1) 
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) 
        {
            err -= dy;
            x1 += sx;
        }
        
        if (e2 < dx) 
        {
            err += dx;
            y1 += sy;
        }
    }
}

void    map_size(t_data *dta)
{
    while(dta->map[dta->height])
    {
        dta->width = 0;
        while(dta->map[dta->height][dta->width])
            dta->width++;
        dta->height++;
    }
    printf("height : %d\n", dta->height);
    printf("width : %d\n", dta->width);
}

// void    check_line(t_data *dta)
// {
//     while(dta->map[dta->posy])
//     {
//         dta->posx = 0;
//         while(dta->map[dta->posy][dta->posx])
//         {
            
//         }
//     }
// }
