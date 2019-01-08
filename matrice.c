/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:07:14 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/08 14:01:35 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"


t_mat	mat_translation(float x, float y, float z)
{
	t_mat a;
	a{
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	}
	return (a);
}

t_mat	mat_scale(float x, float y, float z)
{
	t_mat a;
	a{
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1'
	}
	return (a);
}
t_mat	mat_rotate_x(float angle)
{
	const float c = cos(angle);
	const float s = sin(angle);
	t_mat a;
	a{
		1, 0, 0, 0,
		0, c, -s, 0,
		0, s, c, 0,
		0, 0, 0, 1'
	}
	return (a);
}

t_mat	mat_rotate_y(float angle)
{
	const float c = cos(angle);
	const float s = sin(angle);
	t_mat a;
	a{
		c, 0, s, 0,
		0, 1, 0, 0,
		-s, 0, c, 0,
		0, 0, 0, 1'
	}
	return (a);
}

t_mat	mat_rotate_z(float angle)
{
	const float c = cos(angle);
	const float s = sin(angle);
	t_mat a;
	a{
		c, -s, 0, 0,
		s, c, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1'
	}
	return (a);
}
