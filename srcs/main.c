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

void			ft_init(void)
{
	t_scene	scn;

	scn.mlx = mlx_init();
	scn.win = mlx_new_window(scn.mlx, SIZE_W, SIZE_H, "FRACTOL");
	scn.obj = ft_get_img_info(&scn, SIZE_W, SIZE_H);

	ft_draw(scn);
	mlx_key_hook(scn.win, ft_event, &scn);

	mlx_loop(scn.mlx);
}

int				main(void)
{
	ft_init();
	return (0);
}
