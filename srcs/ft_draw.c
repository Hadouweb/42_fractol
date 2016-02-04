#include "fractol.h"

void		ft_generate_image(t_img *obj, int x, int y, unsigned int color)
{
	if (y < 0 || y > SIZE_H - 1 || x < 0 || x > SIZE_W - 1)
		return ;
	color = 0;
	obj->data[y * obj->sizeline + x * obj->bpp / 8] = 0;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 1] = 255;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 2] = 255;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 3] = 1;
}

void			ft_draw(t_scene scn)
{
	double x1 = -0.5;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	double ite_max = scn.ite_max;
	double zoom = scn.zoom;

	double image_x = (x2 - x1) * zoom;
	double image_y = (y2 - y1) * zoom;
	double 	x;
	double 	y;

	x = 0;
	while (x < image_x)
	{
		y = 0;
	   	while (y < image_y)
	   	{
	        double c_r = x / zoom + x1;
	        double c_i = y / zoom + y1;
	        double z_r = 0;
	        double z_i = 0;
	        double i = 0;

	        while (z_r * z_r + z_i * z_i < 4 && i < ite_max)
	        {
	            double tmp = z_r;
	            z_r = z_r * z_r - z_i * z_i + c_r;
	            z_i = 2 * z_i * tmp + c_i;
	            i++;
	        }
	        if (i == ite_max)
	            ft_generate_image(scn.obj, x, y, 0x000000);
	        else
	        	ft_generate_image(scn.obj, x, y, i * 255 / ite_max);
	    	y++;
	    }
	    x++;
	}
	mlx_put_image_to_window(scn.mlx, scn.win, scn.obj, SIZE_W / 2, SIZE_H / 2);
}
