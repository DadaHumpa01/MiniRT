#include "../includes/minirt.h" 

t_vector	cy_normal(t_object *cy, t_vector p)
{
	t_object	plane;
	t_global	temp;

	plane.dir = cy->dir;
	plane.ori = cy->ori;
	temp.t = INT_MAX;
	create_plane(&temp, &plane, p, cy->dir);
	if (temp.t != INT_MAX)
	{
		return (vec_normalize(vec_sub(p, vec_add(cy->ori,
						vec_mul_float(cy->dir, temp.t * -1)))));
	}
	create_plane(&temp, &plane, p, vec_mul_float(cy->dir, -1));
	return (vec_normalize(vec_sub(p, vec_add(cy->ori,
					vec_mul_float(cy->dir, temp.t)))));
}
