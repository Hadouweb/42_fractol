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

static t_img	*ft_get_img_info(t_scene *scn, int width, int height)
{
	t_img	*obj;

	obj = (t_img *)ft_memalloc(sizeof(t_img));
	obj->img = mlx_new_image(scn->mlx, width, height);
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

void			ft_init_name(t_scene *scn)
{
	scn->init_fractal[0] = ft_init_mandelbrot;
	scn->init_fractal[1] = ft_init_julia;
	scn->init_fractal[2] = ft_init_burningship;
	scn->calc[0] = ft_calc_mandelbrot;
	scn->calc[1] = ft_calc_julia;
	scn->calc[2] = ft_calc_burningship;
}

static void		ft_init(t_scene *scn)
{
	scn->mlx = mlx_init();
	scn->win = mlx_new_window(scn->mlx, SIZE_W, SIZE_H, "FRACTOL");
	scn->obj = ft_get_img_info(scn, SIZE_W, SIZE_H);
	scn->f = scn->init_fractal[scn->id_f]();
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

	mlx_loop(scn->mlx);
}

int				main(int ac, char **av)
{
	int 	i;
	t_scene	scn;

	i = 1;
	if (ac < 2)
		ft_error();
	else
	{
		while (i < ac)
		{
			ft_check_name(av[i], &scn);
			i++;
		}
	}
	ft_init_name(&scn);
	ft_init(&scn);
	return (0);
}
