/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:41:56 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/07 16:18:25 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/*int	tracertrait(t_data *fdf, int x0, int y0, int x1, int y1)
  {
  int	dx;
  int	dy;
  int	dp;
  int	deltaE;
  int	deltaNE;
  int	x;
  int	y;

  x0 *= 50;
  y0 *= 50;
  x1 *= 50;
  y1 *= 50;
  dx = x1 - x0;
  printf("x0 = %d -- y0 = %d -- x1 = %d -- y1 = %d\n", x0, y0, x1, y1);
  dy = y1 - y0;
  dp = 2 * dy - dx;
  deltaE = 2 * dy;
  deltaNE = 2 * (dy - dx);
  x = x0;
  y = y0;
  mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
  while (x < x1)
  {
  if (dp <= 0)
  {
  dp = dp + deltaE;
  x++;
  }
  else
  {
  dp = dp + deltaNE;
  x++;
  y++;
  }
  mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
  }
  return (0);
  }*/

int tracertrait(t_data *fdf, int x, int y, int xstart, int ystart)
{
	float x1;
	int xend;
	float y1;
	float pas;
	float i;
	float t;
	float t2;

	printf("x = %d -- y = %d -- x1 = %d -- y1 = %d\n", x, y, xstart, ystart);
	i = 0;
	x *= fdf->dim;
	y *= fdf->dim;
	xstart *= fdf->dim;
	ystart *= fdf->dim;
	x1 = xstart > x ? x : xstart;
	xend = xstart > x ? xstart : x;
	t = ((float)y -(float)ystart) / ((float)x - (float)xstart);
	t2 = (float)y - (float)x * t;
	pas = x > xstart ? (float)(x - xstart) / 100 : (float)(xstart - x) / 100;
	if (pas != 0)
	{
		while (x1 <= xend)
		{
			y1 = t * x1 + t2;
			printf("Je viens de mettre un pixel1\n");
			mlx_pixel_put(fdf->mlx, fdf->win, x1, y1, 0xFFFFFF);
			x1 += pas;
		}
	}
	else
	{
		i = 0;
		y1 = ystart > y ? y : ystart;
		pas = ystart > y ? ystart - y : y - ystart;
		while (i <= 500)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, x1, y1 + (i / 500) * pas, 0xFFFFFF);
			printf("Je viens de mettre un pixel2\n");
			i++;
		}
	}
	return (1);
}

int		algo(t_data *fdf, int x, int y)
{
	int		i;
	int		j;
	int		z;

	z = 1;
	fdf->dim = x > y ? 900 / x : 900 / y;
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
				tracertrait(fdf, (i * (fdf->z[j][i] + 1)), (j * (fdf->z[j][i] + 1)), ((i + 1) * (fdf->z[j][i + 1] + 1)), (j * (fdf->z[j][i] + 1)));
			}
			if (i - 1 >= 0)
			{
				z = fdf->z[j][i - 1];
				z = z == 0 ? 0 : 1;
				tracertrait(fdf, (i * (fdf->z[j][i] + 1)), (j * (fdf->z[j][i] + 1)), ((i - 1) * (fdf->z[j][i - 1] + 1)), (j * (fdf->z[j][i] + 1)));
			}
			if (j + 1 < y)
			{
				z = fdf->z[j + 1][i];
				z = z == 0 ? 0 : 1;
				tracertrait(fdf, (i * (fdf->z[j][i] + 1)), (j * (fdf->z[j][i] + 1)), (i * (fdf->z[j][i] + 1)), ((j + 1) * (fdf->z[j + 1][i] + 1)));
			}
			if (j - 1 >= 0)
			{
				z = z == 0 ? 0 : 1;
				tracertrait(fdf, (i * (fdf->z[j][i] + 1)), (j * (fdf->z[j][i] + 1)), (i * (fdf->z[j][i] + 1)), ((j - 1) * (fdf->z[j - 1][i] + 1)));
			}
			i++;
		}
		j++;
	}
	return (0);
}
