/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:41:56 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/09 13:52:47 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int gradient(int a, int b, float percent)
{
	return ((int)((a + (b - a)) * percent));
}

int tracertrait(t_data *fdf, int xstart, int ystart, int x, int y, int dz, int zstart)
{
	const int	x_inc = xstart < x ? 1 : -1;
	const int	y_inc = ystart < y ? 1 : -1;
	const int	dx = x > xstart ? x - xstart: xstart - x;
	const int	dy = y > ystart ? y - ystart: ystart - y;
	int			e[2];
	double		i;

	e[0] = dx > dy ? dx / 2 : -dy / 2;
	while (xstart != x || ystart != y)
	{
		i = (dx > dy) ? (x - xstart) * x_inc / (double)dx : (y - ystart) * y_inc / (double)dy;
		if (ystart >= 0 && ystart < SCREEN_Y && y < SCREEN_Y && y >= 0 && xstart >= 0 && xstart < SCREEN_X && x < SCREEN_X && x > 0)
			fdf->img_ptr[ystart * SCREEN_X + xstart] = 0xFFFFFF - gradient(0xFF0000, 0x00FF00, (zstart + (i * dz)) / (double)(fdf->more));
//			fdf->img_ptr[ystart * SCREEN_X + xstart] = gradient(0xFF0000, 0x00FF00, (dx > dy) ? (x - xstart) * x_inc / (double)dx : (y - ystart) * y_inc / (double)dy);
		if ((e[1] = e[0]) > -dx)
		{
			e[0] -= dy;
			xstart += x_inc;
		}
		if (e[1] < dy)
		{
			e[0] += dx;
			ystart += y_inc;
		}
	}
	return (0);
}

static int	ft_pass_iso(t_data *fdf, int xstart, int ystart, int x, int y)
{
	int	tmp1;
	int tmp2;
	int		zstart;
	int		z;

	zstart = fdf->z[ystart][xstart];
	z = fdf->z[y][x];
	x *= fdf->zoom;
	y *= fdf->zoom;
	xstart *= fdf->zoom;
	ystart *= fdf->zoom;
	tmp1 = x;
	tmp2 = xstart;
	x = (x - y) + fdf->position_x;
	xstart = (xstart - ystart) + fdf->position_x;
	y = ((tmp1 + y) / 2) + fdf->position_y;
	ystart = ((tmp2 + ystart) / 2) + fdf->position_y;
	tracertrait(fdf, xstart - (zstart * fdf->hauteur), ystart - (zstart * fdf->hauteur), x - (z * fdf->hauteur), y - (z * fdf->hauteur), zstart - z, zstart);
	return (1);
}

static	int	ft_pass(t_data *fdf, int xstart, int ystart, int x, int y)
{
	if (fdf->isoparr == 0)
		ft_pass_iso(fdf, xstart, ystart, x, y);
	else if (fdf->isoparr == 1)
	{
		int	z;
		int	zstart;

		zstart = fdf->z[ystart][xstart];
		z = fdf->z[y][x];
		x *= fdf->zoom;
		y *= fdf->zoom;
		xstart *= fdf->zoom;
		ystart *= fdf->zoom;
		x += fdf->position_x;
		y += fdf->position_y;
		xstart += fdf->position_x;
		ystart += fdf->position_y;
		tracertrait(fdf, xstart - (zstart * fdf->hauteur), ystart - (zstart * fdf->hauteur), x - (z * fdf->hauteur), y - (z * fdf->hauteur), zstart - z, zstart);
	}
	return (0);
}

int		algo(t_data *fdf, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (i + 1 < x)
				ft_pass(fdf, i, j, (i + 1), j);
			if (i - 1 >= 0)
				ft_pass(fdf, i, j, (i - 1), j);
			if (j + 1 < y)
				ft_pass(fdf, i, j, i, (j + 1));
			if (j - 1 >= 0)
				ft_pass(fdf, i, j, i, (j - 1));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}
