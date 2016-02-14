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

int		main(int ac, char **av)
{
	int		i;
	int		nbr;
	t_app	app;

	i = 1;
	nbr = NB_FRACTAL;
	if (ac < 2)
		ft_error("Bad number args\n");
	else
	{
		ft_bzero(app.id_win, nbr * sizeof(int));
		while (i < ac)
		{
			ft_check_name(av[i], &app);
			i++;
		}
	}
	ft_init_app(&app);
	sleep(10);
	return (0);
}
