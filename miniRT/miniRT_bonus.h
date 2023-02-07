/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:37:21 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/07 18:27:16 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "miniRT.h"

void		my_mlx_pixel_put_bonus(t_img *img, int x, int y, t_elements *ele);
void		drawing_bonus(t_set *set);
t_vec3		ray_color_bonus(t_elements *ele);
t_vec3		hit_bonus(t_elements *ele, t_hit_record *rec, t_ray *ray);
bool		init_bonus(int ac, char **av, t_elements *element, t_set *set);
int			parse_cone(char **buffer, t_elements *element);
void		hit_co(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret);
int			key_hook_bonus(int keycode, t_set *set);
void		set_keyhook_bonus(t_set *set);
t_select	*select_object_bonus(t_set *set);
int			hit_cone(t_cone *co, t_ray *ray, t_hit_record *rec);
t_vec3		phong_light_bonus(t_elements *ele, t_hit_record *rec);
int			parse_l_bonus(char **buffer, t_elements *element);
void		free_all_bonus(t_elements *ele, t_set *set);
int			parse_sphere_bonus(char **buffer, t_elements *element, t_set *set);
void		hit_sp_bonus(t_elements *ele, t_hit_record *rec, \
						t_ray *ray, t_vec3 *ret);
void		hit_pl_bonus(t_elements *ele, t_hit_record *rec, \
						t_ray *ray, t_vec3 *ret);
t_vec3		my_mlx_pixel_get(t_xpm *data, int x, int y);
t_vec3		rander_texture_map(t_sphere *sp, t_vec3 p);
t_vec3		get_bump_map(t_sphere *sp, t_vec3 p);
t_vec3		get_normal_vector(t_sphere *sp, t_hit_record *rec);

#endif
