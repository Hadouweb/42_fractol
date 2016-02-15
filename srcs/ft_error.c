/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 00:39:56 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/15 00:39:57 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_error_print_param(char *str)
{
	ft_putstr_fd("Error : '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("' is invalid\n", 2);
	ft_putstr_fd("\t - mandelbrot\n", 2);
	ft_putstr_fd("\t - julia\n", 2);
	ft_putstr_fd("\t - burningship\n", 2);
	ft_putstr_fd("\t - mandelbar\n", 2);
	exit(1);
}

void	ft_check_name(char *name, t_app *app)
{
	int			i;
	int			find;

	app->n[0] = "mandelbrot";
	app->n[1] = "julia";
	app->n[2] = "burningship";
	app->n[3] = "mandelbar";
	i = 0;
	find = 0;
	while (i < NB_FRACTAL)
	{
		if (ft_strcmp(name, app->n[i]) == 0)
		{
			find = 1;
			if (app->id_win[i])
				ft_error_print_param("Duplicate param");
			app->id_win[i] = 1;
		}
		i++;
	}
	if (!find)
		ft_error_print_param(name);
}
