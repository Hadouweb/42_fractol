#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h" 
# include <stdio.h>

# define SIZE_H 500
# define SIZE_W 500

# define KEY_ESC 53
# define ITE_UP 8
# define ITE_DOWN 9

typedef struct		s_img
{
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
}					t_img;

typedef struct		s_scene
{
	void			*mlx;
	void			*win;
	t_img			*obj;
	int 			zoom;
	int 			ite_max;
}					t_scene;

void			ft_draw(t_scene scn);
int				ft_event(int keycode, t_scene *scn);
int				ft_event_mouse(int button, int x, int y, t_scene *scn);

#endif