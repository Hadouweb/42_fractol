#include "fractol.h"

int		ft_event(int keycode, t_scene *scn)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	else if (keycode == ITE_UP)
		scn->ite_max += 10;
	else if (keycode == ITE_DOWN)
		scn->ite_max -= 10;
	//mlx_clear_window(scn->mlx, scn->win);
	ft_draw(*scn);
	return (1);
}

int		ft_event_mouse(int button, int x, int y, t_scene *scn)
{
	printf("%d %d %d\n", x, y, button);
	if (x)
		;
	if (y)
		;
	if (button == 5)
		scn->zoom += 100;
	else if (button == 5)
		scn->zoom -= 100;
	//mlx_clear_window(scn->mlx, scn->win);
	ft_draw(*scn);

	return (1);
}