#include "fractol.h"

void			ft_create_text(t_scene *scn)
{
	mlx_string_put(scn->mlx, scn->win, 20, 10, 0x0EEAFF, "Translate Top   : ^");
	mlx_string_put(scn->mlx, scn->win, 280, 10, 0x0EEAFF, "Translate Bot   : v");
	mlx_string_put(scn->mlx, scn->win, 530, 10, 0x0EEAFF, "Translate Left  : <");
	mlx_string_put(scn->mlx, scn->win, 780, 10, 0x0EEAFF, "Translate Right : >");

	mlx_string_put(scn->mlx, scn->win, 20, 40, 0x15A9FA, "Mandelbrot      : 1");
	mlx_string_put(scn->mlx, scn->win, 280, 40, 0x15A9FA, "Julia           : 2");
	mlx_string_put(scn->mlx, scn->win, 530, 40, 0x15A9FA, "Burningship     : 3");
	mlx_string_put(scn->mlx, scn->win, 780, 40, 0x15A9FA, "mandelbar       : 4");

	mlx_string_put(scn->mlx, scn->win, 20, 70, 0x1B76FF, "Zoom            : Mouse wheel");
	mlx_string_put(scn->mlx, scn->win, 530, 70, 0x1B76FF, "Dezoom          : Mouse wheel");

	mlx_string_put(scn->mlx, scn->win, 20, 100, 0x1C3FFD, "Iteration up    : c");
	mlx_string_put(scn->mlx, scn->win, 530, 100, 0x1C3FFD, "Iteration down  : v");

	mlx_string_put(scn->mlx, scn->win, 20, 130, 0x2C1DFF, "Random color    : r");
	mlx_string_put(scn->mlx, scn->win, 530, 130, 0x2C1DFF,
		"Activ random color for zoom : CMD");

	mlx_string_put(scn->mlx, scn->win, 20, 160, 0x1C13A3, "Menu            : z");
	mlx_string_put(scn->mlx, scn->win, 530, 160, 0x1C13A3, "Exit            : esc");
}

void			ft_create_menu(t_scene *scn)
{
	int		x;
	int		y;

	y = 0;
	while (y < 200)
	{
		x = 0;
		while (x < SIZE_W)
		{
			ft_generate_image(scn->menu, x, y, ft_get_color(0, 200, 255, 255 - y));
			x++;
		}
		y++;
	}
}