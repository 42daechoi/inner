/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:52:12 by daechoi           #+#    #+#             */
/*   Updated: 2022/12/12 17:07:07 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "vector3.h"
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
// # include <mlx.h>
# include "ray.h"
# include <stdio.h>

# define X_EVENT_KEYPRESS		2
# define X_EVENT_DESTROYNOTIFY	17
# define WIDTH	400
# define HEIGHT 300

# define CAM 0
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define LIGHT 4
# define CONE 5

# define INCREASE 0
# define DECREASE 1

# define EPSILON 1e-6

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	norm;
	int		fov;
	t_vec3	hor;
	t_vec3	ver;
	t_vec3	llc;
}	t_camera;

typedef struct s_light
{
	t_vec3			pos;
	double			ratio;
	int				red;
	int				green;
	int				blue;
	struct s_light	*next;
}	t_light;

typedef struct s_xpm
{
	char			*img;
	int				img_w;
	int				img_h;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	unsigned char	*addr;
}	t_xpm;

typedef struct s_sphere
{
	t_vec3			pos;
	double			dia;
	int				red;
	int				green;
	int				blue;
	struct s_sphere	*next;
	t_xpm			texture;
	t_xpm			bump;
}	t_sphere;

typedef struct s_plane
{
	t_vec3			pos;
	t_vec3			norm;
	int				red;
	int				green;
	int				blue;
	struct s_plane	*next;
	bool			ischeck;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3				pos;
	t_vec3				norm;
	double				dia;
	double				height;
	int					red;
	int					green;
	int					blue;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_cone
{
	t_vec3			pos;
	t_vec3			normal;
	double			theta;
	double			height;
	int				red;
	int				green;
	int				blue;
	struct s_cone	*next;
}	t_cone;

typedef struct s_select
{
	int			type;
	t_camera	*cam;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	t_cone		*co;
	t_light		*light;
	int			mouse_x;
	int			mouse_y;
}	t_select;

typedef struct s_ambient
{
	double	ratio;
	int		red;
	int		green;
	int		blue;
}	t_ambient;

typedef struct s_elements
{
	t_ambient	*amb;
	t_camera	*cam;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_cone		*cone;
	t_ray		*ray;
	int			sphere_cnt;
	int			plane_cnt;
	int			cylinder_cnt;
	int			cone_cnt;
}	t_elements;

typedef struct s_set
{
	void		*mlx;
	void		*win;
	t_select	*select;
	t_elements	*ele;
	t_img		*img;
}	t_set;

void		print_manual(void);
void		set_isfront(t_ray *ray, t_hit_record *rec);
void		move_rotate(int keycode, t_set *set);
void		fixed_camera(t_camera *cam, t_ray *ray);
void		resize(t_select *select, int flag);
bool		hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
bool		hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec);
t_select	*select_object(t_set *set);
void		rotate_y(t_select *select, int flag);
void		rotate_z(t_select *select, int flag);
t_select	*init_select(t_camera *cam, t_light *light);
void		rotate_x(t_select *select, int flag);
void		move_x(t_select *select, int flag);
void		move_y(t_select *select, int flag);
void		move_z(t_select *select, int flag);
t_vec3		phong_light(t_elements *ele, t_hit_record *rec);
t_vec3		hit(t_elements *ele, t_hit_record *rec, t_ray *ray);
void		free_char(char **buffer);
int			parse_c(char **buffer, t_elements *element);
int			parse_a(char **buffer, t_elements *element);
int			parse_l(char **buffer, t_elements *element);
int			parse_plane(char **buffer, t_elements *element);
int			parse_cylinder(char **buffer, t_elements *element);
int			parse_sphere(char **buffer, t_elements *element);
void		ft_exit(int a);
int			is_end_rt(char *file);
bool		split_type(char **temp, t_elements *element);
bool		split_newline(int fd, t_elements *element);
void		init_variable(t_elements *element);
bool		init(int ac, char **av, t_elements *element);
int			split_num(char **buffer);
void		set_mlx(t_set *set, t_elements *ele);
void		drawing(t_set *set);
void		my_mlx_pixel_put(t_img *img, int x, int y, t_elements *ele);
int			exit_game(t_set *set);
void		set_keyhook(t_set *set);
void		hit_sp(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret);
void		hit_pl(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret);
void		set_isfront(t_ray *ray, t_hit_record *rec);
void		hit_cy(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret);
int			hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
double		minf(double a, double b);
double		maxf(double a, double b);
void		hit_co(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret);
void		free_all(t_elements *ele, t_set *set);
bool		cal_root(double a, double half_b, double c, t_hit_record *rec);
int			mouse_hook(int button, int x, int y, t_set *set);
bool		hit_sp_select(t_set *set, t_hit_record *rec, t_ray *ray);
bool		hit_pl_select(t_set *set, t_hit_record *rec, t_ray *ray);
bool		hit_cy_select(t_set *set, t_hit_record *rec, t_ray *ray);
void		my_mlx_pixel_put(t_img *img, int x, int y, t_elements *ele);
void		fixed_camera(t_camera *cam, t_ray *ray);

#endif
