#include "fractol.h"

int		ft_event(int keycode, t_scene *scn)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (scn->mlx)
		;
	return (1);
}