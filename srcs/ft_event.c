/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 00:29:47 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/15 00:29:50 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_switch_fractal(int keycode, t_app *app)
{
	int		id;

	id = -1;
	if (keycode == KEY_MANDELBROT)
		id = 0;
	else if (keycode == KEY_JULIA)
		id = 1;
	else if (keycode == KEY_BURNINGSHIP)
		id = 2;
	else if (keycode == KEY_MANDELBAR)
		id = 3;
	else
		return (0);
	if (id != -1)
	{
		app->scn[app->c]->f = ft_init_fractal();
		app->scn[app->c]->calc = app->calc[id];
		if (id == 1)
			app->move = 1;
		else
			app->move = 0;
	}
	return (1);
}

int			ft_event(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
		ft_destroy_win(app);
	else if (keycode == KEY_ITE_UP)
		app->scn[app->c]->f->ite_max += 5;
	else if (keycode == KEY_ITE_DOWN)
		app->scn[app->c]->f->ite_max -= 5;
	else if (keycode == KEY_CMD)
	{
		if (app->scn[app->c]->cmd)
			app->scn[app->c]->cmd = 0;
		else
			app->scn[app->c]->cmd = 1;
	}
	else if (keycode == KEY_CS_RAND)
		ft_rand_color(app->scn[app->c]);
	else if (ft_switch_fractal(keycode, app))
		;
	else
		return (0);
	ft_bzero(app->scn[app->c]->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(app->scn[app->c]);
	return (1);
}

int			ft_expose(t_scene *scn)
{
	int		i;

	i = 0;
	scn->app->c = scn->id;
	return (1);
}

int			ft_event_julia(int x, int y, t_scene *scn)
{
	if (scn->app->move && x > 0 && x < SIZE_W && y > 0 && y < SIZE_H)
	{
		scn->f->formcr = ((double)x - scn->pos_x) / scn->f->zoom;
		scn->f->formci = ((double)y - scn->pos_y) / scn->f->zoom;
		ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
		ft_draw(scn);
	}
	return (1);
}

int			ft_event_mouse(int button, int x, int y, t_scene *scn)
{
	double	h;

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
		scn->f->x1 -= ((double)x - scn->pos_x) / scn->f->zoom / 6;
		scn->f->y1 -= ((double)y - scn->pos_y) / scn->f->zoom / 6;
		scn->f->zoom /= h;
		scn->f->ite_max -= 1;
	}
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_draw(scn);
	return (1);
}
