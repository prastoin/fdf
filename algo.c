/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:41:56 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/08 16:58:48 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int tracertrait(t_data *fdf, int xstart, int ystart, int x, int y)
{
	const int	x_inc = xstart < x ? 1 : -1;
	const int	y_inc = ystart < y ? 1 : -1;
	const int	dx = x > xstart ? x - xstart: xstart - x;
	const int	dy = y > ystart ? y - ystart: ystart - y;
	int			e[2];
	int color = 0xFFFFFF;

	e[0] = dx > dy ? dx / 2 : -dy / 2;
//	printf("OUIOUI\n");
	while (xstart != x || ystart != y)
	{
		if (ystart >= 0 && ystart < 1000 && y < 1000 && y >= 0 && xstart >= 0 && xstart < 1000 && x < 1000 && x > 0)
			fdf->img_ptr[ystart * 1000 + xstart] = color;
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

static int	ft_pass(t_data *fdf, int xstart, int ystart, int x, int y)
{
	int	tmp1;
	int tmp2;
	int		zstart;
	int		z;

	zstart = fdf->z[ystart][xstart];
	z = fdf->z[y][x];
//	printf("zstart = %d z = %d\n", zstart, z);
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
	tracertrait(fdf, xstart - (zstart * fdf->hauteur), ystart - (zstart * fdf->hauteur), x - (z * fdf->hauteur), y - (z * fdf->hauteur));
	return (1);
}

int		algo(t_data *fdf, int x, int y)
{
	int		i;
	int		j;
	int		z;

	z = 1;
	j = 0;
	printf("x = %d y = %d\n", x, y);
	while (j < y)
	{
		i = 0;
		printf("j = %d\n", j);
		while (i < x)
		{
			//			printf("z[%d][%d] = %d\n", j, i, fdf->z[j][i]);
			if (i + 1 < x)
			{
				//				fdf->z[j][i] = fdf->z[j][i] == 0 ? 0 : (fdf->z[j][i + 1] / 10);
				//				fdf->z[j][i + 1] = fdf->z[j][i + 1] == 0 ? 0 : (fdf->z[j][i + 1] / 10);
				ft_pass(fdf, i, j, (i + 1), j);
			}
			if (i - 1 >= 0)
			{
//				z = fdf->z[j][i - 1];
//				z = z == 0 ? 0 : 1;
				ft_pass(fdf, i, j, (i - 1), j);
			}
			if (j + 1 < y)
			{
				ft_pass(fdf, i, j, i, (j + 1));
			}
			if (j - 1 >= 0)
			{
				ft_pass(fdf, i, j, i, (j - 1));
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}
