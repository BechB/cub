/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:21:10 by aldalmas          #+#    #+#             */
/*   Updated: 2024/10/02 16:22:06 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    get_map(t_map *m)
{
    (void)m;
}

void    ft_error(char *error_msg)
{
    printf(RED "ERROR\n-> %s\n" RESET, error_msg);
    // free les potentiels tabs
    exit (1);
}

void parsing(t_map *m, int ac, char **av)
{
    (void)av;
    (void)m;
    
    init_struct(m, av[1]);
    if (ac != 2)
        ft_error("Invalid number of args (only '.cub' file needed)");
}
