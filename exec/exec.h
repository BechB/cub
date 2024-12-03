/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:12:42 by bbousaad          #+#    #+#             */
/*   Updated: 2024/12/03 17:44:50 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
#define EXEC_H

# define BLACK2   0x000000
# define WHITE2   0xFFFFFF
# define RED2     0xFF0000
# define GREEN2   0x00FF00
# define BLUE2    0x0000FF
# define YELLOW2  0xFFFF00
# define CYAN2    0x00FFFF
# define MAGENTA2 0xFF00FF
# define ORANGE2  0xFFA500
# define PURPLE2  0x800080
# define GREY2    0x808080
# define ESC	  65307
# define UP		  65362
# define LEFT     65361
# define DOWN     65364
# define RIGHT    65363
# define PI		  3.1415926535
#define FOV 60
#define ang 360
#define PI 3.1415926535
#define PLAYER_MOVE_SPEED 0.1
#define PLAYER_ROTATE_SPEED 0.05

typedef struct s_player {
    double x;
    double y;
    double angle;
}              t_player;

typedef struct s_game {
    void    *mlx;
    void    *window;
    t_player player;
}              t_game;

typedef struct s_img {
	void	*img;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_y;
	int		img_x;
}				t_img;

typedef struct s_data
{
    void    *mlx;
    void    *win;
	int		size;
	int		posy;
	int		posx;
	int		pdx;
	int		pdy;
	int		pa;
	int		playerX;
	int		playerY;
	int		playerAngle;
	int		p_x;
	int		p_y;
	int		height;
	int		width;
	char	**map;
	char	**mapa;
	t_img	north;
    t_img   south;
    t_img   east;
    t_img   west;
	t_img	floor;
}               t_data;

void	ft_exit(t_data *dta, char *mess, int status);
void    ft_error(char *error_msg);
void    open_win(t_data *dta);
int		put_img(t_data *dta);
void    check_img(t_data *dta);
int		leave(int key, t_data *dta);
void	readmap(t_data	*dta, char	**argv);
void	handle_img(t_data *dta);
void	put_mini(t_data *dta, int i, int j);
void	draw_big_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int size, int color);
void    init_spawn(t_data *dta);
void	map_size(t_data *dta);
int		key_press(int keycode, t_data *dta);
void 	draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int color);
#endif