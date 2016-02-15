/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 00:21:11 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/15 00:21:13 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*ft_get_name(t_app *app, int id)
{
	char	*name;
	char	*tmp_name;
	char	*tmp_id;
	char	*tmp_id2;
	char	*itoa_id;

	if ((name = ft_strdup(app->n[id])) == NULL)
		ft_error("Malloc name\n");
	if (name[0])
	{
		name[0] -= 32;
		tmp_name = name;
		itoa_id = ft_itoa(id);
		tmp_id = ft_strdup(" [");
		tmp_id2 = ft_strjoin(tmp_id, itoa_id);
		ft_strdel(&tmp_id);
		ft_strdel(&itoa_id);
		tmp_id = ft_strjoin(tmp_id2, "]");
		ft_strdel(&tmp_id2);
		name = ft_strjoin(tmp_name, tmp_id);
		ft_strdel(&tmp_id);
		ft_strdel(&tmp_name);
	}
	return (name);
}

void		ft_rand_color(t_scene *scn)
{
	int		t;

	t = 100;
	scn->cs[0] = ft_get_color(0, 0, 0, 0);
	scn->cs[1] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[2] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[3] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[4] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
}

void		ft_destroy_win(t_app *app)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	app->id_win[app->c] = 0;
	i = 0;
	while (i < NB_FRACTAL)
	{
		if (app->id_win[i])
			find = 1;
		i++;
	}
	mlx_destroy_window(app->mlx, app->scn[app->c]->win);
	i = 0;
	while (i < NB_FRACTAL)
	{
		if (app->id_win[i])
			app->c = i;
		i++;
	}
	if (!find)
		exit(0);
}

int			ft_expose(t_scene *scn)
{
	int		i;

	i = 0;
	scn->app->c = scn->id;
	return (1);
}

void		ft_swap_menu_cmd(t_app *app, int token)
{
	if (token)
	{
		if (app->scn[app->c]->cmd)
			app->scn[app->c]->cmd = 0;
		else
			app->scn[app->c]->cmd = 1;
	}
	else
	{
		if (app->scn[app->c]->d_menu)
			app->scn[app->c]->d_menu = 0;
		else
			app->scn[app->c]->d_menu = 1;
	}
}
