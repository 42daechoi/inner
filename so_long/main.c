#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define X_EVENT_KEYPRESS		2
#define X_EVENT_KEYRELEASE		3

#define KEYCODE_W   			13
#define KEYCODE_A   			0
#define KEYCODE_S   			1
#define KEYCODE_D   			2
#define KEYCODE_ESC				53

typedef	struct s_param
{
	int	x;
	int	y;
} t_param;

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

int	press_key(int keycode, t_param *param)
{
	if (keycode == KEYCODE_A)
		param->y++;
	else if (keycode == KEYCODE_S)
		param->x--;
	else if (keycode == KEYCODE_D)
		param->y--;
	else if (keycode == KEYCODE_W)
		param->x++;
	else if (keycode == KEYCODE_ESC)
		exit(0);
	printf("x : %d, y : %d\n", param->x, param->y);
	return (0);
}

int main(void)
{
	t_param	param;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	param_init(&param);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_hook(win_ptr, X_EVENT_KEYPRESS, 0, &press_key, &param);
	mlx_loop(mlx_ptr);
	return (0);
}