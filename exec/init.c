/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:38:23 by aldalmas          #+#    #+#             */
/*   Updated: 2024/12/03 17:40:27 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_struct(t_map *m, char *map_path)
{
    m->fd = open(map_path, O_RDONLY);
    if (m->fd == -1)
        ft_error("Wrong map file");
}

int key_press(int keycode, t_data *dta)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (keycode == ESC)
    {
        printf(RED"RAGE QUIT !?\n"RESET);
        mlx_destroy_window(dta->mlx, dta->win);
        exit(0);
    }
    else if (keycode == UP)
    {
        draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, GREY2);
        dta->posy = dta->posy - 4;
        draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, RED2);
        printf("TOUCHE HAUT\n");
        i = i + 5;
    }
    else if (keycode == DOWN)
    {
        draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, GREY2);
        dta->posy = dta->posy + 4;
        draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, RED2);
        printf("TOUCHE BAS\n");
        i = i - 5;
    }
    else if (keycode == LEFT)
    {
        draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, GREY2);
        draw_line(dta->mlx, dta->win, dta->posx, dta->posy, dta->posx + 20, dta->posy + 20, GREY2);
        draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, RED2);
        draw_line(dta->mlx, dta->win, dta->posx, dta->posy, dta->posx + 20, dta->posy + 20, RED2);
        printf("TOUCHE GAUCHE\n");
    }
    else if (keycode == RIGHT)
    {
        draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, GREY2);
        draw_line(dta->mlx, dta->win, dta->posx, dta->posy, dta->posx + 20, dta->posy + 20, GREY2);
        dta->pa += 0.1;
        if(dta->pa > 2 * PI)
        {
            dta->pa -= 2 * PI;
            dta->pdx = cos(dta->pa) * 5;
            dta->pdy = sin(dta->pa) * 5;
        }
        draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, RED2);
        draw_line(dta->mlx, dta->win, dta->posx, dta->pdy, dta->posx + 20, dta->posy + 20, GREY2);
        printf("TOUCHE DROITE\n");
    }
	put_mini(dta, i, j);
	init_spawn(dta);
    return (0);
}

void    init_spawn(t_data *dta)
{
    draw_big_pixel(dta->mlx, dta->win, dta->posx, dta->posy, 8, RED2);
    draw_line(dta->mlx, dta->win, dta->posx, dta->posy, dta->posx + 20, dta->posy + 20, RED2);
    printf("x : %d y : %d\n", dta->posx, dta->posy);
    dta->p_y = (PI / 2) - FOV/2;
}