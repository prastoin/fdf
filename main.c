/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/09 16:03:56 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static int	deal_key(int key, t_data *fdf)
{
	if (key == KEY_LESS)
		fdf->zoom -= 5;
	if (key == KEY_PLUS)
		fdf->zoom += 5;
	if (key == KEY_UP)
		fdf->position_y += 15;
	if (key == KEY_DOWN)
		fdf->position_y -= 15;
	if (key == KEY_RIGHT)
		fdf->position_x += 15;
	if (key == KEY_LEFT)
		fdf->position_x -= 15;
	if (key == KEY_SPACE)
		ft_quit(fdf);
	if (key == KEY_NUM6)
		fdf->hauteur++;
	if (key == KEY_NUM3)
		fdf->hauteur--;
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, SCREEN_X, SCREEN_Y);
	fdf->img_ptr = (int *)mlx_get_data_addr(fdf->img, &key, &key, &key);
	algo(fdf, fdf->ab, fdf->ord);
	return (0);
}

static int	ft_count_line(t_data *fdf)
{
	int		tet;
	char	*line;
	char	*tmp;

	tmp = NULL;
	fdf->ord = 0;
	tet = 1;
	while (tet > 0)
	{
		tmp = line;
		if ((tet = get_next_line(fdf->fd, &line)) < 0)
			return (-1);
		if (tmp != NULL)
			free(tmp);
		fdf->ord++;
	}
	fdf->ord--;
	return (0);
}

static void	ft_init(t_data *fdf)
{
	fdf->zoom = 53;
	fdf->position_x = SCREEN_X / 4;
	fdf->position_y = SCREEN_Y / 4;
	fdf->hauteur = 1;
	fdf->more = 0;
	fdf->less = 0;
}

static int	ft_cut(t_data *fdf, int i)
{
	if (parser(fdf, 0) == -1)
	{
		ft_putstr("Invalid map\n");
		return (-1);
	}
	close(fdf->fd);
	data(fdf);
	ft_freedbchar(fdf->tab);
	get_z_max(fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, SCREEN_X, SCREEN_Y, "prastoin's fdf");
	fdf->img = mlx_new_image(fdf->mlx, SCREEN_X, SCREEN_Y);
	fdf->img_ptr = (int *)mlx_get_data_addr(fdf->img, &i, &i, &i);
	algo(fdf, fdf->ab, fdf->ord);
	mlx_key_hook(fdf->win, deal_key, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	fdf;

	ft_init(&fdf);
	if (argc == 3 && (ft_strcmp(argv[2], "iso") == 0
				|| ft_strcmp(argv[2], "parr") == 0))
	{
		fdf.isoparr = (ft_strcmp(argv[2], "iso") == 0) ? 0 : 1;
		if ((fdf.fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		if ((ft_count_line(&fdf)) == -1)
			return (0);
		close(fdf.fd);
		if ((fdf.fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
	}
	else
	{
		ft_putstr("./fdf [map] [projection] (iso / parr)\n");
		return (0);
	}
	if (ft_cut(&fdf, 5) == -1)
		return (0);
	ft_freedbint(fdf.z, fdf.ord);
	return (0);
}
