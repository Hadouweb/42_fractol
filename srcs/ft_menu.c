#include "fractol.h"

static	void	ft_create_menu_tranform(t_scene *scn)
{
	unsigned int	c;

	c = 0xffffff;
	mlx_string_put(scn->mlx, scn->win, 20, 10, c, "Rotate X Top   : W");
	mlx_string_put(scn->mlx, scn->win, 20, 25, c, "Rotate X Bot   : S");
	mlx_string_put(scn->mlx, scn->win, 20, 45, c, "Rotate Y Left  : A");
	mlx_string_put(scn->mlx, scn->win, 20, 60, c, "Rotate Y Right : D");
	mlx_string_put(scn->mlx, scn->win, 20, 80, c, "Rotate Z Left  : Q");
	mlx_string_put(scn->mlx, scn->win, 20, 95, c, "Rotate Z Right : E");
	mlx_string_put(scn->mlx, scn->win, 230, 10, c, "Translate Top   : ^");
	mlx_string_put(scn->mlx, scn->win, 230, 25, c, "Translate Bot   : v");
	mlx_string_put(scn->mlx, scn->win, 230, 40, c, "Translate Left  : <");
	mlx_string_put(scn->mlx, scn->win, 230, 55, c, "Translate Right : >");
}

static	void	ft_create_menu_map(t_scene *scn)
{
	unsigned int	c;

	c = 0xffffff;
	mlx_string_put(scn->mlx, scn->win, 700, 10, c, "Map 42          : X");
	mlx_string_put(scn->mlx, scn->win, 700, 25, c, "Map elem        : C");
	mlx_string_put(scn->mlx, scn->win, 700, 40, c, "Map pyra        : V");
	mlx_string_put(scn->mlx, scn->win, 700, 55, c, "Map pyramide    : B");
	mlx_string_put(scn->mlx, scn->win, 700, 70, c, "Map nle-bret    : N");
	mlx_string_put(scn->mlx, scn->win, 700, 85, c, "Map Japan_L     : M");
	mlx_string_put(scn->mlx, scn->win, 700, 100, c, "Map France_XXL  : <");
}

void			ft_create_text(t_scene *scn)
{
	unsigned int	c;

	c = 0xffffff;
	ft_create_menu_tranform(scn);
	ft_create_menu_map(scn);
	mlx_string_put(scn->mlx, scn->win, 20, 140, c, "Projection Iso      : I");
	mlx_string_put(scn->mlx, scn->win, 20, 155, c, "Projection Parallel : P");
	mlx_string_put(scn->mlx, scn->win, 310, 140, c, "Color 1 : !");
	mlx_string_put(scn->mlx, scn->win, 310, 155, c, "Color 2 : @");
	mlx_string_put(scn->mlx, scn->win, 480, 140, c, "Color 3      : #");
	mlx_string_put(scn->mlx, scn->win, 480, 155, c, "Color Random : $");
	mlx_string_put(scn->mlx, scn->win, 440, 10, c, "Translate Zoom + : T");
	mlx_string_put(scn->mlx, scn->win, 440, 25, c, "Translate Zoom - : R");
	mlx_string_put(scn->mlx, scn->win, 440, 45, c, "Scale Z Up +     : G");
	mlx_string_put(scn->mlx, scn->win, 440, 60, c, "Scale Z Bot -    : F");
	mlx_string_put(scn->mlx, scn->win, 700, 150, c, "Exit            : ESC");
}

void			ft_create_menu(t_scene *scn)
{
	int		x;
	int		y;

	y = 0;
	while (y < 200)
	{
		x = 0;
		while (x < SIZE_W)
		{
			ft_generate_image(scn->menu, x, y, ft_get_color(45, 45, 55, 100));
			x++;
		}
		y++;
	}
}