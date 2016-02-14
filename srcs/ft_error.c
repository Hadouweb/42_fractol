#include "fractol.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_check_name(char *name, t_scene *scn)
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
			scn->id_f = i;
		}
		i++;
	}
	if (!find)
		ft_error();
}