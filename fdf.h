/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/08 16:47:58 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define KEY_LESS 69
# define KEY_PLUS 78
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
//# define W_L 1000
//# define W_l 1000

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*ximg;
	void	*img;
	int		*img_ptr;

	int		dim; //??
	char	*tab[4096];
	int		fd;
	int		ord; //ordonnes
	int		ab; //abscisss
	int		**z; //tab altitude

	int		zoom;
	int		position_y;
	int		position_x;
}			t_data;

typedef struct	s_mat
{
	float m11;
	float m12;
	float m13;
	float m14;
	float m21;
	float m22;
	float m23;
	float m24;
	float m31;
	float m32;
	float m33;
	float m34;
	float m41;
	float m42;
	float m43;
	float m44;
}		t_mat;

int		parser(t_data *fdf);
int		data(t_data *fdf);
int		algo(t_data *fdf, int x, int y);

t_mat	mat_translation(float x, float y, float z);
t_mat	mat_scale(float x, float y, float z);
t_mat	mat_rotate_x(float angle);
t_mat	mat_rotate_y(float angle);
t_mat	mat_rotate_z(float angle);

#endif
