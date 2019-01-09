/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:08:15 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/09 15:50:31 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	ft_quit(t_data *fdf)
{
	ft_freedbint(fdf->z, fdf->ord);
	exit(0);
}

void	ft_tracertrait_cut(t_data *fdf, int x, int y, int dz)
{
	if (fdf->ystart >= 0 && fdf->ystart < SCREEN_Y
			&& y < SCREEN_Y && y >= 0 && fdf->xstart >= 0
			&& fdf->xstart < SCREEN_X && x < SCREEN_X && x > 0)
		fdf->img_ptr[fdf->ystart * SCREEN_X + fdf->xstart] = 0xFFFFFF
			- gradient(0xFF0000, 0x00FF00, (fdf->zstart + (fdf->grad * dz))
			/ (double)(fdf->more));
	return ;
}
