#include "fractol.h"

static int 	ft_move(int keycode, t_scene *scn)
{
	if (keycode == KEY_UP)
		scn->pos_y -= 10;
	if (keycode == KEY_DOWN)
		scn->pos_y += 10;
	if (keycode == KEY_LEFT)
		scn->pos_x -= 10;
	if (keycode == KEY_RIGHT)
		scn->pos_x += 10;

	return (1);
}

int 		ft_event_repeat(int keycode, t_scene *scn)
{
	ft_move(keycode, scn);
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);
	return (1);
}