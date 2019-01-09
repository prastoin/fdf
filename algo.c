/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:41:56 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/09 14:52:27 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int		gradient(int a, int b, float percent)
{
	return ((int)((a + (b - a)) * percent));
}

static int		tracertrait(t_data *fdf, int x, int y, int dz)
{
	const int	x_inc = fdf->xstart < x ? 1 : -1;
	const int	y_inc = fdf->ystart < y ? 1 : -1;
	const int	dx = x > fdf->xstart ? x - fdf->xstart : fdf->xstart - x;
	const int	dy = y > fdf->ystart ? y - fdf->ystart : fdf->ystart - y;
	int			e[2];

	e[0] = dx > dy ? dx / 2 : -dy / 2;
	while (fdf->xstart != x || fdf->ystart != y)
	{
		fdf->grad = (dx > dy) ? (x - fdf->xstart) * x_inc / (double)dx :
			(y - fdf->ystart) * y_inc / (double)dy;
		if (fdf->ystart >= 0 && fdf->ystart < SCREEN_Y &&
				y < SCREEN_Y && y >= 0 && fdf->xstart >= 0 &&
				fdf->xstart < SCREEN_X && x < SCREEN_X && x > 0)
			fdf->img_ptr[fdf->ystart * SCREEN_X + fdf->xstart] = 0xFFFFFF -
				gradient(0xFF0000, 0x00FF00, (fdf->zstart + (fdf->grad * dz)) /
				(double)(fdf->more));
		if ((e[1] = e[0]) > -dx)
		{
			e[0] -= dy;
			fdf->xstart += x_inc;
		}
		if (e[1] < dy)
		{
			e[0] += dx;
			fdf->ystart += y_inc;
		}
	}
	return (0);
}

static int		ft_pass_iso(t_data *fdf, int x, int y)
{
	int		tmp1;
	int		tmp2;
	int		z;

	fdf->zstart = fdf->z[fdf->ystart][fdf->xstart];
	z = fdf->z[y][x];
	x *= fdf->zoom;
	y *= fdf->zoom;
	fdf->xstart = fdf->xstart * fdf->zoom;
	fdf->ystart = fdf->ystart * fdf->zoom;
	tmp1 = x;
	tmp2 = fdf->xstart;
	x = (x - y) + fdf->position_x;
	fdf->xstart = (fdf->xstart - fdf->ystart) + fdf->position_x;
	y = ((tmp1 + y) / 2) + fdf->position_y;
	fdf->ystart = ((tmp2 + fdf->ystart) / 2) + fdf->position_y;
	fdf->xstart = fdf->xstart - (fdf->zstart * fdf->hauteur);
	fdf->ystart = fdf->ystart - (fdf->zstart * fdf->hauteur);
	tracertrait(fdf, x - (z * fdf->hauteur), y - (z * fdf->hauteur),
	fdf->zstart - z);
	return (1);
}

static int		ft_pass(t_data *fdf, int x, int y)
{
	int	z;

	fdf->xstart = fdf->x;
	fdf->ystart = fdf->y;
	if (fdf->isoparr == 0)
		ft_pass_iso(fdf, x, y);
	else if (fdf->isoparr == 1)
	{
		fdf->zstart = fdf->z[fdf->ystart][fdf->xstart];
		z = fdf->z[y][x];
		x *= fdf->zoom;
		y *= fdf->zoom;
		fdf->xstart = fdf->xstart * fdf->zoom - (fdf->zstart * fdf->hauteur);
		fdf->ystart = fdf->ystart * fdf->zoom - (fdf->zstart * fdf->hauteur);
		x += fdf->position_x;
		y += fdf->position_y;
		fdf->xstart += fdf->position_x;
		fdf->ystart += fdf->position_y;
		tracertrait(fdf, x - (z * fdf->hauteur), y - (z * fdf->hauteur),
				fdf->zstart - z);
	}
	return (0);
}

int				algo(t_data *fdf, int x, int y)
{
	fdf->x = 0;
	fdf->y = 0;
	while (fdf->y < y)
	{
		fdf->x = 0;
		while (fdf->x < x)
		{
			if (fdf->x + 1 < x)
				ft_pass(fdf, (fdf->x + 1), fdf->y);
			if (fdf->x - 1 >= 0)
				ft_pass(fdf, (fdf->x - 1), fdf->y);
			if (fdf->y + 1 < y)
				ft_pass(fdf, fdf->x, (fdf->y + 1));
			if (fdf->y - 1 >= 0)
				ft_pass(fdf, fdf->x, (fdf->y - 1));
			fdf->x++;
		}
		fdf->y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}
