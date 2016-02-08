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

t_fractal		*ft_init_mandelbrot(void)
{
	t_fractal 	*f;

	f = (t_fractal*)ft_memalloc(sizeof(t_fractal));
	f->zoom = 100;
	f->ite_max = 50;
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -2;
	f->y2 = 1.2;
	return (f);
}

void			ft_get_colorset(t_scene	*scn)
{
	scn->cs[0] = ft_get_color(0, 0, 0, 0);
	scn->cs[1] = ft_get_color(120, 0, 0, 0);
	scn->cs[2] = ft_get_color(180, 0, 0, 0);
	scn->cs[3] = ft_get_color(100, 200, 250, 0);
	scn->cs[4] = ft_get_color(250, 250, 250, 0);
}

void			ft_init(void)
{
	t_scene	scn;

	scn.mlx = mlx_init();
	scn.win = mlx_new_window(scn.mlx, SIZE_W, SIZE_H, "FRACTOL");
	scn.obj = ft_get_img_info(&scn, SIZE_W, SIZE_H);
	scn.f = ft_init_mandelbrot();
	ft_get_colorset(&scn);
	scn.pos_x = 0;
	scn.pos_y = 0;

	ft_draw(&scn);
	mlx_hook(scn.win, 4, 1L<<6, ft_event_mouse, &scn);
	mlx_hook(scn.win, 2, 3, ft_event_repeat, &scn);
	mlx_key_hook(scn.win, ft_event, &scn);

	mlx_loop(scn.mlx);
}

int				main(void)
{
	ft_init();
	return (0);
}
