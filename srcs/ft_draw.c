#include "fractol.h"

void		ft_generate_image(t_img *obj, int x, int y, t_color color)
{
	if (y < 0 || y > SIZE_H - 1 || x < 0 || x > SIZE_W - 1)
		return ;
	obj->data[y * obj->sizeline + x * obj->bpp / 8] = color.r;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 1] = color.g;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 2] = color.b;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 3] = color.a;
}

t_color		ft_get_color(unsigned char r, unsigned char g,
	unsigned char b, unsigned char a)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
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
    cr = (double)x / scn->f->zoom + scn->f->x1;
    ci = (double)y / scn->f->zoom + scn->f->y1;
    while (zr * zr + zi * zi < 4 && ite < scn->f->ite_max)
    {
        tmp = zr;
        zr = zr * zr - zi * zi + cr;
        zi = 2 * zi * tmp + ci;
        ite++;
    }
    return (ite);
}

t_color			ft_choice_color(t_scene *scn, int i)
{
	t_color	color;
	int 	nbr;

	nbr = scn->f->ite_max / 5;
	if (i == scn->f->ite_max)
		color = ft_get_color(0, 0, 100, 0);
	else if (i < nbr)
		color = ft_get_color(i * 255 / nbr, i * 255 / nbr, i * 255 / nbr, 0);
	else if (i < nbr * 2)
		color = ft_get_color(i * 255 / nbr, i * 200 / nbr, i * 255 / nbr, 0);
	else
		color = ft_get_color(i * 100 / nbr, i * 100 / nbr, i * 100 / nbr, 0);
	return (color);
}

void			ft_draw(t_scene *scn)
{
	int 	x;
	int 	y;
	int 	i;

	i = 0;
	x = 0;
	while (x < SIZE_W)
	{
		y = 0;
	   	while (y < SIZE_H)
	   	{
	   		i = ft_calc_mandelbrot(scn, x, y, 0);
	   		//printf("___%d\n", i);
		    ft_generate_image(scn->obj, x, y, ft_choice_color(scn, i));
			y++;
	    }
	    x++;
	}
	mlx_put_image_to_window(scn->mlx, scn->win, scn->obj->img, 0, 0);
}
