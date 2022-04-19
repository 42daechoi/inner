#include "solong.h"

void	param_init(t_gameset *gameset)
{
	gameset->x = 0;
	gameset->y = 0;
}

int	press_key(int keycode, t_gameset *gameset)
{
	if (keycode == KEYCODE_A)
		gameset->y++;
	else if (keycode == KEYCODE_S)
		gameset->x--;
	else if (keycode == KEYCODE_D)
		gameset->y--;
	else if (keycode == KEYCODE_W)
		gameset->x++;
	else if (keycode == KEYCODE_ESC)
		exit(0);
	return (0);
}

void	image_rendering(void *mlx_ptr, void *win_ptr)
{
	void	*img_land;
	void	*img_wall;
	void	*img_;
	void	*img4;
	void	*img5;
	int 	img_size = 64;

	img_land = mlx_xpm_file_to_image(mlx_ptr, "./tile.xpm", &img_size, &img_size);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_land, 0, 0);
}

int main(int argc, char **argv)
{
	t_gameset	gameset;
	void		*mlx_ptr;
	void		*win_ptr;

	if (argc != 2)
		write(2, "ERROR\n", 6);
	read_map(argv[1], &gameset);
	printf("%s\n",gameset.map_line);
	mlx_ptr = mlx_init();
	param_init(&gameset);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	image_rendering(mlx_ptr, win_ptr);
	mlx_hook(win_ptr, X_EVENT_KEYPRESS, 0, &press_key, &gameset);
	mlx_loop(mlx_ptr);
	return (0);
}