#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h" 

# define SIZE_H 500
# define SIZE_W 500

# define KEY_ESC 53

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
}					t_scene;

void			ft_draw(t_scene scn);
int				ft_event(int keycode, t_scene *scn);

#endif