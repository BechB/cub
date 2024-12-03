/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:56:51 by aldalmas          #+#    #+#             */
/*   Updated: 2024/11/09 15:24:08 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    (void) ac;
    //t_map   m;
    t_data *dta;
    //t_game game;

    dta = malloc(sizeof(t_data));
    //parsing(&m, ac, av);
    readmap(dta, av);
    open_win(dta);
    //start(game);
    // mlx_new_window(NULL, 200, 200, "test");
    return (0);
}
