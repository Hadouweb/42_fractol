#include "fractol.h"

static int 	ft_event_color(int keycode, t_scene *scn)
{
	if (keycode == KEY_CS_RAND)
	{
		scn->cs[0] = ft_get_color(0, 0, 0, 0);
		scn->cs[1] = ft_get_color(rand(), rand(), rand(), 0);
		scn->cs[2] = ft_get_color(rand(), rand(), rand(), 0);
		scn->cs[3] = ft_get_color(rand(), rand(), rand(), 0);
		scn->cs[4] = ft_get_color(rand(), rand(), rand(), 0);
	}
	return (1);
}

int			ft_event(int keycode, t_scene *scn)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_ITE_UP)
		scn->f->ite_max += 5;
	else if (keycode == KEY_ITE_DOWN)
		scn->f->ite_max -= 5;
	else if (keycode == KEY_CMD)
	{
		if (scn->cmd)
			scn->cmd = 0;
		else
			scn->cmd = 1;
	}
	ft_event_color(keycode, scn);
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);
	return (1);
}

int 		ft_event_julia(int x, int y, t_scene *scn)
{
	scn->f->form = (double)(x * y) / (SIZE_W * SIZE_H) * 2;
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);
	return (1);
}

static void	ft_rand_color(t_scene *scn)
{
	int 	t;

	t = 100;
	scn->cs[0] = ft_get_color(0, 0, 0, 0);
	scn->cs[1] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[2] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[3] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[4] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
}

int			ft_event_mouse(int button, int x, int y, t_scene *scn)
{
	float 	h;

	h = 1.1;
	if (button == KEY_ZOOM && scn->f->zoom < 1073379187320315)
	{	
		if (scn->cmd)
			ft_rand_color(scn);
 		scn->f->x1 += ((float)x - scn->pos_x) / scn->f->zoom / 10;
 		scn->f->y1 += ((float)y - scn->pos_y) / scn->f->zoom / 10;
		scn->f->ite_max += 1;
		scn->f->zoom *= h;
	}
	else if (button == KEY_DEZOOM && scn->f->zoom > 10)
	{
		scn->f->x1 -= ((float)x - scn->pos_x) / scn->f->zoom / 10;
 		scn->f->y1 -= ((float)y - scn->pos_y) / scn->f->zoom / 10;
		scn->f->zoom /= h;
		scn->f->ite_max -= 1;
	}
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);
	return (1);
}