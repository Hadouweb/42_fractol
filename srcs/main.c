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
	scn->app->current = scn->id;
	printf("CURRENT %d\n", scn->app->current);
	return (1);
}

static void		ft_init_scene(t_scene *scn, int id)
{
	scn->win = mlx_new_window(scn->mlx, SIZE_W, SIZE_H, ft_itoa(id));
	scn->obj = ft_get_img_info(scn->mlx, SIZE_W, SIZE_H);
	scn->f = ft_init_fractal();
	scn->id = id;
	ft_init_colorset(scn);
	scn->pos_x = SIZE_W / 2 - fabs(scn->f->zoom * scn->f->x1);
	scn->pos_y = SIZE_H / 2 - fabs(scn->f->zoom * scn->f->y1);
	scn->cmd = 0;

	ft_draw(scn);
	mlx_hook(scn->win, 4, 1L<<6, ft_event_mouse, scn);
	if (scn->id_f == 1)
		mlx_hook(scn->win, 6, 1L<<6, ft_event_julia, scn);
	mlx_hook(scn->win, 2, 3, ft_event_repeat, scn);
	mlx_key_hook(scn->win, ft_event, scn);
	mlx_key_hook(scn->win, ft_event, scn);
	mlx_expose_hook(scn->win, ft_expose, scn);
}

void 			ft_cpy_app_scn(t_app *app)
{
	int 	i;

	i = 0;
	while (i < NB_FRACTAL)
	{
		if (app->id_win[i])
		{
			app->scn[i].mlx = app->mlx;
			app->scn[i].app = app;
			app->scn[i].calc = app->calc[0];
			ft_init_scene(&app->scn[i], i);
			app->current = i;
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
