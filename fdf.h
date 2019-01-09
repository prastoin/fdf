/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/09 16:16:17 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

# define KEY_LESS 78
# define KEY_PLUS 69
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 53
# define KEY_NUM6 88
# define KEY_NUM3 85
# define SCREEN_X 1000
# define SCREEN_Y 1000

typedef struct		s_data
{
	void	*mlx;
	void	*win;
	void	*ximg;
	void	*img;
	int		*img_ptr;

	int		dim;
	char	**tab;
	int		fd;
	int		ord;
	int		ab;
	int		**z;
	int		more;
	int		less;

	int		zoom;
	int		position_y;
	int		position_x;
	int		hauteur;
	int		isoparr;

	int		x;
	int		y;
	int		xstart;
	int		ystart;
	int		zstart;
	double	grad;
}					t_data;

int					gradient(int a, int b, float percent);
void				ft_tracertrait_cut(t_data *fdf, int x, int y, int dz);
void				ft_quit(t_data *fdf);
int					get_z_max(t_data *fdf);
int					parser(t_data *fdf, int i);
int					data(t_data *fdf);
int					algo(t_data *fdf, int x, int y);

#endif
