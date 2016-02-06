#include "fractol.h"

int		ft_event(int keycode, t_scene *scn)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	else if (keycode == ITE_UP)
		scn->f->ite_max += 10;
	else if (keycode == ITE_DOWN)
		scn->f->ite_max -= 10;
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);
	return (1);
}

int		ft_event_mouse(int button, int x, int y, t_scene *scn)
{
	float 	h;

	h = 1.1;
	if (button == 5 && scn->f->zoom < 1073379187320315)
	{
		scn->f->zoom *= h;
 		scn->f->x1 += (float)x / scn->f->zoom / 10;
 		scn->f->x2 += (float)x / scn->f->zoom / 10;
 		scn->f->y1 += (float)y / scn->f->zoom / 10;
 		scn->f->y2 += (float)y / scn->f->zoom / 10;
		scn->f->ite_max += 1;
	}
	else if (button == 4 && scn->f->zoom > 10)
	{
		scn->f->zoom /= h;
 		scn->f->x1 -= (float)x / scn->f->zoom / 10;
 		scn->f->x2 -= (float)x / scn->f->zoom / 10;
 		scn->f->y1 -= (float)y / scn->f->zoom / 10;
 		scn->f->y2 -= (float)y / scn->f->zoom / 10;
		scn->f->ite_max -= 1;
	}
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);

	return (1);
}