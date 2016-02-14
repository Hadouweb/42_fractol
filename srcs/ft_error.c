#include "fractol.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_check_name(char *name, t_app *app)
{
	int			i;
	int			find;

	app->n[0] =	"mandelbrot";
	app->n[1] = "julia";
	app->n[2] =	"burningship";
	app->n[3] =	"mandelbar";
	i = 0;
	find = 0;
	while (i < NB_FRACTAL)
	{
		if (ft_strcmp(name, app->n[i]) == 0)
		{
			find = 1;
			app->id_win[i] = 1;
		}
		i++;
	}
	if (!find)
		ft_error("This fractal does not exist\n");
}