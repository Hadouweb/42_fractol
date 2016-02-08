#include "fractol.h"

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

int 			ft_calc_mandelbrot(t_scene *scn, int x, int y, int ite)
{
	double 	zr;
    double 	zi;
    double 	cr;
    double 	ci;
    double	tmp;

    zr = 0;
    zi = 0;
    cr = (double)x / scn->f->zoom + scn->f->x1 - (scn->pos_x / scn->f->zoom);
    ci = (double)y / scn->f->zoom + scn->f->y1 - (scn->pos_y / scn->f->zoom);
    while (zr * zr + zi * zi < 4 && ite < scn->f->ite_max)
    {
        tmp = zr;
        zr = zr * zr - zi * zi + cr;
        zi = 2 * zi * tmp + ci;
        ite++;
    }
    return (ite);
}