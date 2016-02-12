#include "fractol.h"

t_fractal		*ft_init_mandelbrot(void)
{
	t_fractal 	*f;

	f = (t_fractal*)ft_memalloc(sizeof(t_fractal));
	f->zoom = 200;
	f->ite_max = 50;
	f->x1 = -2.1;
	f->y1 = -2;
    f->form = 0;
	return (f);
}

t_fractal       *ft_init_julia(void)
{
    t_fractal   *f;

    f = (t_fractal*)ft_memalloc(sizeof(t_fractal));
    f->zoom = 200;
    f->ite_max = 50;
    f->x1 = -1;
    f->y1 = -1.2;
    f->form = 0.01;
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

int             ft_calc_julia(t_scene *scn, int x, int y, int ite)
{
    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  tmp;

    zr = (double)x / scn->f->zoom + scn->f->x1 - (scn->pos_x / scn->f->zoom);
    zi = (double)y / scn->f->zoom + scn->f->y1 - (scn->pos_y / scn->f->zoom);
    cr = 0.285 + scn->f->form;
    ci = 0.01 + scn->f->form;
    while (zr * zr + zi * zi < 4 && ite < scn->f->ite_max)
    {
        tmp = zr;
        zr = zr * zr - zi * zi + cr;
        zi = 2 * zi * tmp + ci;
        ite++;
    }
    return (ite);
}