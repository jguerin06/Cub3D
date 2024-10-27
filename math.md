void	draw_3d(t_opt *opt)
{
	int			ray_index;
	double		fov;
	double		start_angle;
	double		angle_step;
	double		cos_angle;
	double		sin_angle;
	t_vector	next;
	int			facing;
	double		next_x;
	double		next_y;
	double		dist;

	ray_index = 0;
	fov = 90 * (PI / 180);
	start_angle = opt->pa - (fov / 2);
	angle_step = fov / WIDTH;
	if (opt->wall_img)
		mlx_delete_image(opt->mlx, opt->wall_img);
	opt->wall_img = mlx_new_image(opt->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(opt->mlx, opt->wall_img, 0, 0);
	opt->wall_img->instances[0].z = 1;
	while (ray_index < WIDTH)
	{
		next = (t_vector){opt->x, opt->y, 0};
		while (1)
		{
			cos_angle = cos(start_angle + angle_step * ray_index);
			sin_angle = sin(start_angle + angle_step * ray_index);
			next = next_grid_intersector(next, start_angle + angle_step
					* ray_index, 0, 0);
			next_x = next.x;
			next_y = next.y;
			next.x += cos_angle / 100;
			next.y += sin_angle / 100;
			if (opt->map[(int)(next.y / MAPSQUARE)][(int)(next.x
					/ MAPSQUARE)] == '1')
			{
				if (cos_angle > 0)
				{
					if (sin_angle > 0) // Q1
					{
						if (is_vertical(next_x, next_y)) // O1
							facing = 1;
						else // O2
							facing = 0;
					}
					else // Q4
					{
						if (is_vertical(next_x, next_y)) // O8
							facing = 1;
						else // O7
							facing = 2;
					}
				}
				else
				{
					if (sin_angle > 0) // Q2
					{
						if (is_vertical(next_x, next_y)) // O4
							facing = 3;
						else // O3
							facing = 0;
					}
					else // Q3
					{
						if (is_vertical(next_x, next_y)) // O5
							facing = 3;
						else
							facing = 2; // O6
					}
				}
				dist = sqrt((next_x - opt->x) * (next_x - opt->x) + (next_y
							- opt->y) * (next_y - opt->y));
				render_wall(opt, ray_index, dist, facing, facing % 2
						* fmod((next_y) / MAPSQUARE, 1) + (1 - facing % 2)
						* fmod((next_x) / MAPSQUARE, 1));
				break ;
			}
		}
		ray_index++;
	}
}
