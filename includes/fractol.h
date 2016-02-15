/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 00:44:39 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/15 00:44:40 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <time.h>
# include <math.h>

# define SIZE_H 1000
# define SIZE_W 1000

# define KEY_ESC 53

# define KEY_ITE_UP 8
# define KEY_ITE_DOWN 9

# define KEY_CMD 259

# define KEY_CS_RAND 15

# define KEY_ZOOM 4
# define KEY_DEZOOM 5

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define NB_FRACTAL 4

# define KEY_MANDELBROT 18
# define KEY_JULIA 19
# define KEY_BURNINGSHIP 20
# define KEY_MANDELBAR 21

# define KEY_MENU 6

typedef struct s_img		t_img;
typedef struct s_color		t_color;
typedef struct s_fractal	t_fractal;
typedef struct s_scene		t_scene;
typedef struct s_app		t_app;

struct				s_img
{
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
};

struct				s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

struct				s_fractal
{
	double			zoom;
	int				ite_max;
	double			x1;
	double			y1;
	double			formcr;
	double			formci;
};

struct				s_scene
{
	t_app			*app;
	void			*mlx;
	int				(*calc)(struct s_scene *scn, int x, int y, int ite);
	int				id;
	char			*name;
	void			*win;
	t_img			*obj;
	t_img			*menu;
	t_fractal		*f;
	t_color			cs[5];
	int				pos_x;
	int				pos_y;
	int				cmd;
	int 			d_menu;
};

struct				s_app
{
	t_scene			*scn[NB_FRACTAL];
	void			*mlx;
	int				(*calc[NB_FRACTAL])(struct s_scene *scn,
		int x, int y, int ite);
	int				id_win[NB_FRACTAL];
	int				c;
	int				move;
	char			*n[NB_FRACTAL];
};

t_fractal			*ft_init_fractal(void);
int					ft_calc_mandelbrot(t_scene *scn, int x, int y, int ite);
int					ft_calc_julia(t_scene *scn, int x, int y, int ite);
int					ft_calc_burningship(t_scene *scn, int x, int y, int ite);
int					ft_calc_mandelbar(t_scene *scn, int x, int y, int ite);

int					ft_event_repeat(int keycode, t_scene *scn);

int					ft_event(int keycode, t_app *app);
int					ft_event_mouse(int button, int x, int y, t_scene *scn);
int					ft_event_julia(int x, int y, t_scene *scn);

void				ft_generate_image(t_img *obj, int x, int y, t_color color);
t_color				ft_get_color(unsigned char r, unsigned char g,
						unsigned char b, unsigned char a);
void				ft_draw(t_scene *scn);

void				ft_error(char *str);
void				ft_check_name(char *name, t_app *app);
int					ft_expose(t_scene *scn);

void				ft_init_app(t_app *app);
char				*ft_get_name(t_app *app, int id);
void				ft_rand_color(t_scene *scn);
void				ft_destroy_win(t_app *app);

void				ft_create_text(t_scene *scn);
void				ft_create_menu(t_scene *scn);
void				ft_calc_color(t_scene *scn);

#endif
