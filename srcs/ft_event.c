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
	int 	h;

	h = 20;
	printf("%d %d %d\n", x, y, button);
	if (x)
		;
	if (y)
		;
	if (button == 5)
	{
		scn->f->x1 -= x / SIZE_W;
		scn->f->x2 += x / SIZE_W;
		scn->f->y1 -= y / SIZE_H;
		scn->f->y2 += y / SIZE_H;
		scn->f->zoom += h;
		scn->f->ite_max += h;
				printf("%f\n", scn->f->x1);
	}
	else if (button == 4)
	{
		scn->f->x1 += x / SIZE_W;
		scn->f->x2 -= x / SIZE_W;
		scn->f->y1 += y / SIZE_H;
		scn->f->y2 -= y / SIZE_H;
		scn->f->zoom -= h;
		scn->f->ite_max -= h;
	}
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);

	return (1);
}