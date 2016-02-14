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

void		ft_destroy_win(t_app *app)
{
	int		i;
	int 	find;

	i = 0;
	find = 0;
	app->id_win[0] = 0;
	while (i < NB_FRACTAL)
	{
		if (app->id_win[i])
			find = 1;
		i++;
	}
	if (!find)
		exit(1);
}

int			ft_event(int keycode, t_scene *scn)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(scn->mlx, scn->win);
		printf("DESTROY : %d\n", scn->id);
		ft_destroy_win(scn->app);
		return (1);
	}
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
	if (x > 0 && x < SIZE_W && y > 0 && y < SIZE_H)
	{
		scn->f->formcr = ((double)x - scn->pos_x) / scn->f->zoom;
		scn->f->formci = ((double)y - scn->pos_y) / scn->f->zoom;
		ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
		ft_draw(scn);
	}
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
	double 	h;

	h = 1.2;
	if (button == KEY_ZOOM)
	{	
		if (scn->cmd)
			ft_rand_color(scn);
 		scn->f->x1 += ((double)x - scn->pos_x) / scn->f->zoom / 6;
 		scn->f->y1 += ((double)y - scn->pos_y) / scn->f->zoom / 6;
		scn->f->ite_max += 1;
		scn->f->zoom *= h;
	}
	else if (button == KEY_DEZOOM && scn->f->zoom > 10)
	{
		scn->f->x1 -= ((double)x - scn->pos_x) / scn->f->zoom / 10;
 		scn->f->y1 -= ((double)y - scn->pos_y) / scn->f->zoom / 10;
		scn->f->zoom /= h;
		scn->f->ite_max -= 1;
	}
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);
	return (1);
}