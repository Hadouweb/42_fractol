/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 06:43:44 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/11 06:43:45 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_img	*ft_get_img_info(void *mlx, int width, int height)
{
	t_img	*obj;

	obj = (t_img *)ft_memalloc(sizeof(t_img));
	obj->img = mlx_new_image(mlx, width, height);
	obj->data = mlx_get_data_addr(obj->img,
		&obj->bpp,
		&obj->sizeline,
		&obj->endian);
	ft_bzero(obj->data, width * height * 4);
	return (obj);
}

static void		ft_init_colorset(t_scene *scn)
{
	scn->cs[0] = ft_get_color(0, 0, 0, 0);
	scn->cs[1] = ft_get_color(120, 0, 0, 0);
	scn->cs[2] = ft_get_color(180, 0, 0, 0);
	scn->cs[3] = ft_get_color(100, 200, 250, 0);
	scn->cs[4] = ft_get_color(250, 250, 250, 0);
}

void			ft_init_name(t_app *app)
{
	app->calc[0] = ft_calc_mandelbrot;
	app->calc[1] = ft_calc_julia;
	app->calc[2] = ft_calc_burningship;
	app->calc[3] = ft_calc_mandelbar;
	app->calc[4] = ft_calc_newton;
}

int 			ft_expose(t_scene *scn)
{
	int 	i;

	i = 0;
	scn->app->c = scn->id;
	printf("CURRENT %d %p\n", scn->app->c, scn->app);
	return (scn->id);
}

static void		ft_init_scene(t_app *app, int id)
{
	app->scn[id]->app = app;
	app->scn[id]->mlx = app->mlx;
	app->scn[id]->calc = app->calc[id];
	app->scn[id]->win = mlx_new_window(app->scn[id]->mlx, SIZE_W, SIZE_H, ft_itoa(id));
	app->scn[id]->obj = ft_get_img_info(app->scn[id]->mlx, SIZE_W, SIZE_H);
	app->scn[id]->f = ft_init_fractal();
	app->scn[id]->id = id;
	ft_init_colorset(app->scn[id]);
	app->scn[id]->pos_x = SIZE_W / 2 - fabs(app->scn[id]->f->zoom * app->scn[id]->f->x1);
	app->scn[id]->pos_y = SIZE_H / 2 - fabs(app->scn[id]->f->zoom * app->scn[id]->f->y1);
	app->scn[id]->cmd = 0;

	ft_draw(app->scn[id]);
	mlx_hook(app->scn[id]->win, 4, 1L<<6, ft_event_mouse, app->scn[id]);
	if (id == 1)
		mlx_hook(app->scn[id]->win, 6, 1L<<6, ft_event_julia, app->scn[id]);
	mlx_hook(app->scn[id]->win, 2, 3, ft_event_repeat, app->scn[id]);
	mlx_key_hook(app->scn[id]->win, ft_event, app);
	mlx_expose_hook(app->scn[id]->win, ft_expose, app->scn[id]);
}

void 			ft_cpy_app_scn(t_app *app)
{
	int 	i;

	i = 0;
	while (i < NB_FRACTAL)
	{
		if (app->id_win[i])
		{
			app->scn[i] = (t_scene*)ft_memalloc(sizeof(t_scene));
			ft_init_scene(app, i);
			app->c = i;
		}
		i++;
	}
}

static void		ft_init_app(t_app *app)
{
	app->mlx = mlx_init();
	ft_cpy_app_scn(app);
	mlx_loop(app->mlx);
}

int				main(int ac, char **av)
{
	int 	i;
	t_app	app;

	i = 1;
	if (ac < 2)
		ft_error();
	else
	{
		bzero(app.id_win, NB_FRACTAL * sizeof(int));
		while (i < ac)
		{
			ft_check_name(av[i], &app);
			i++;
		}
	}
	i = 0;
	while (i < NB_FRACTAL)
	{
		printf("%d \n", app.id_win[i]);
		i++;
	}
	ft_init_name(&app);
	ft_init_app(&app);
	return (0);
}
