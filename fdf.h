/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/08 17:11:18 by prastoin         ###   ########.fr       */
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

# define KEY_LESS 78
# define KEY_PLUS 69
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_CTRL 256
# define KEY_NUM6 88
# define KEY_NUM3 85
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
	int		hauteur;
}			t_data;

int		parser(t_data *fdf);
int		data(t_data *fdf);
int		algo(t_data *fdf, int x, int y);

#endif
