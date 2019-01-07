/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/07 15:22:45 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*ximg;
	void	*img;

	int		dim;
	char	*tab[4096];
	int		fd;
	int		ord;
	int		ab;
	int		**z;
}			t_data;

int		parser(t_data *fdf);
int		data(t_data *fdf);
int		algo(t_data *fdf, int x, int y);

#endif
