#include "fractol.h"

t_fractal		*ft_init_mandelbrot(void)
{
	t_fractal 	*f;

	f = (t_fractal*)ft_memalloc(sizeof(t_fractal));
	f->zoom = 200;
	f->ite_max = 50;
    f->x1 = 0;
    f->y1 = 0;
    f->formcr = 0;
    f->formci = 0;
	return (f);
}

t_fractal       *ft_init_julia(void)
{
    t_fractal   *f;

    f = (t_fractal*)ft_memalloc(sizeof(t_fractal));
    f->zoom = 200;
    f->ite_max = 20;
    f->x1 = 0;
    f->y1 = 0;
    f->formcr = 0;
    f->formci = 0;
    return (f);
}

t_fractal       *ft_init_burningship(void)
{
    t_fractal   *f;

    f = (t_fractal*)ft_memalloc(sizeof(t_fractal));
    f->zoom = 200;
    f->ite_max = 30;
    f->x1 = 0;
    f->y1 = 0;
    f->formcr = 0;
    f->formci = 0;
    return (f);
}

t_fractal       *ft_init_mandelbar(void)
{
    t_fractal   *f;

    f = (t_fractal*)ft_memalloc(sizeof(t_fractal));
    f->zoom = 200;
    f->ite_max = 30;
    f->x1 = 0;
    f->y1 = 0;
    f->formcr = 0;
    f->formci = 0;
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
    cr = scn->f->formcr;
    ci = scn->f->formci;
    while (zr * zr + zi * zi < 4 && ite < scn->f->ite_max)
    {
        tmp = zr;
        zr = zr * zr - zi * zi + cr;
        zi = 2 * zi * tmp + ci;
        ite++;
    }
    return (ite);
}

int             ft_calc_burningship(t_scene *scn, int x, int y, int ite)
{
    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  tmp;

    zr = 0;
    zi = 0;
    cr = (double)x / scn->f->zoom + scn->f->x1 - (scn->pos_x / scn->f->zoom);
    ci = (double)y / scn->f->zoom + scn->f->y1 - (scn->pos_y / scn->f->zoom);
    while (zr * zr + zi * zi < 10 && ite < scn->f->ite_max)
    {
        tmp = zr;
        zr = 2 * fabs(zr * zi) + ci;
        zi = zi * zi - tmp * tmp - cr;
        ite++;
    }
    return (ite);
}

int             ft_calc_mandelbar(t_scene *scn, int x, int y, int ite)
{
    double  zr;
    double  zi;
    double  cr;
    double  ci;
    double  tmp;

    zr = 0;
    zi = 0;
    cr = (double)x / scn->f->zoom + scn->f->x1 - (scn->pos_x / scn->f->zoom);
    ci = (double)y / scn->f->zoom + scn->f->y1 - (scn->pos_y / scn->f->zoom);
    while (zr * zr + zi * zi < 6 && ite < scn->f->ite_max)
    {
        tmp = zr;
        zi *= -1;
        zr = zr * zr - zi * zi + cr;
        zi = 2 * zi * tmp + ci;
        ite++;
    }
    return (ite);
}