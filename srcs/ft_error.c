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
	const char 	*n[NB_FRACTAL] = {"mandelbrot", "julia", "burningship", "mandelbar"};
	int			find;

	i = 0;
	find = 0;
	while (i < NB_FRACTAL)
	{
		if (ft_strcmp(name, n[i]) == 0)
		{
			find = 1;
			app->id_win[i] = 1;
		}
		i++;
	}
	if (!find)
		ft_error("This fractal does not exist\n");
}