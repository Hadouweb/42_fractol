#include "fractol.h"

void			ft_draw(t_scene scn)
{
	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	double image_x = SIZE_W;
	double image_y = SIZE_H;
	double iteration_max = 500;

	double zoom_x = image_x/(x2 - x1);
	double zoom_y = image_y/(y2 - y1);
	double 	x;
	double 	y;

	x = 0;
	while (x < image_x)
	{
		y = 0;
	   	while (y < image_y)
	   	{
	        double c_r = x / zoom_x + x1;
	        double c_i = y / zoom_y + y1;
	        double z_r = 0;
	        double z_i = 0;
	        double i = 0;

	        while (z_r * z_r + z_i * z_i < 4 && i < iteration_max)
	        {
	            double tmp = z_r;
	            z_r = z_r * z_r - z_i * z_i + c_r;
	            z_i = 2 * z_i * tmp + c_i;
	            i++;
	        }

	        if (i == iteration_max)
	            mlx_pixel_put(scn.mlx, scn.win, x, y, 0x00FF00);
	    	y++;
	    }
	    x++;
	}
}
