/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:41:56 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/07 11:30:25 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	tracertrait(t_data *fdf, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	dp;
	int	deltaE;
	int	deltaNE;
	int	x;
	int	y;

	dx = x1 - x0;
	dy = y1 - y0;
	dp = 2 * dy - dx;
	deltaE = 2 * dy;
	deltaNE = 2 * (dy - dx);
	x = x0;
	y = y0;
	printf("je dessine\n");
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
}

int		algo(t_data *fdf, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("algo deb\n");
	while (j < fdf->ord)
	{
		printf("j++\n");
		i = 0;
		while (i < fdf->ab)
		{
			printf("i = %d\n", i);
			printf("%d ", fdf->z[i][j]);
			if (i + 1 < x)
				tracertrait(fdf, fdf->z[j][i], fdf->z[j][i], fdf->z[j][i + 1], fdf->z[j][i]);
			if (i - 1 >= 0)
				tracertrait(fdf, fdf->z[j][i], fdf->z[j][i], fdf->z[j][i - 1], fdf->z[j][i]);
			if (j + 1 < y)
				tracertrait(fdf, fdf->z[j][i], fdf->z[j][i], fdf->z[j + 1][i], fdf->z[j][i]);
			if (j - 1 >= 0)
				tracertrait(fdf, fdf->z[j][i], fdf->z[j][i], fdf->z[j - 1][i], fdf->z[j][i]);
			i++;
		}
		j++;
	}
	return (0);
}
