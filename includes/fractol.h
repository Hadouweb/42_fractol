#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h" 
# include <stdio.h>
# include <time.h>

# define SIZE_H 500
# define SIZE_W 500

# define KEY_ESC 53

# define ITE_UP 8
# define ITE_DOWN 9

# define KEY_CS_RAND 15

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct		s_img
{
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
}					t_img;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef struct 		s_fractal
{
	double 			zoom;
	int 			ite_max;
	double 			x1;
	double 			y1;
	double 			x2;
	double 			y2;
}					t_fractal;

typedef struct		s_scene
{
	void			*mlx;
	void			*win;
	t_img			*obj;
	t_fractal		*f;
	t_color 		cs[5];
	int 			pos_x;
	int 			pos_y;
}					t_scene;

void			ft_draw(t_scene *scn);
int				ft_event(int keycode, t_scene *scn);
int				ft_event_mouse(int button, int x, int y, t_scene *scn);
t_color			ft_get_color(unsigned char r, unsigned char g,
					unsigned char b, unsigned char a);
int 			ft_event_repeat(int keycode, t_scene *scn);

#endif