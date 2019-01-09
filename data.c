/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:15:14 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/09 16:16:02 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int			get_z_max(t_data *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < fdf->ord)
	{
		i = 0;
		while (i < fdf->ab)
		{
			if (fdf->z[j][i] > fdf->more)
				fdf->more = fdf->z[j][i];
			if (fdf->z[j][i] < fdf->less)
				fdf->less = fdf->z[i][j];
			i++;
		}
		j++;
	}
	return (0);
}

static int	ft_numlen(int nb)
{
	int	count;
	int	num;

	count = 0;
	num = nb;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static int	ft_init(int *m, int *n, int *j, int *i)
{
	*m = 0;
	*n = 0;
	*i = 0;
	*j = -1;
	return (0);
}

static int	get_z(t_data *fdf)
{
	int		n;
	int		m;
	int		i;
	int		j;

	ft_init(&m, &n, &j, &i);
	while (fdf->tab[++j])
	{
		i = 0;
		n = 0;
		while (fdf->tab[j][i])
		{
			if (ft_isdigit(fdf->tab[j][i]) == 1 || fdf->tab[j][i] == '-'
					|| fdf->tab[j][i] == '+')
			{
				fdf->z[m][n] = ft_atoi(fdf->tab[j] + i);
				i += ft_numlen(fdf->z[m][n]);
				n++;
			}
			else
				i++;
		}
		m++;
	}
	return (0);
}

int			data(t_data *fdf)
{
	int	i;

	i = 0;
	if (!(fdf->z = (int **)malloc(sizeof(int*) * (fdf->ord))))
		return (-1);
	while (i < fdf->ord)
	{
		if (!(fdf->z[i] = (int *)malloc(sizeof(int) * (fdf->ab))))
			return (-1);
		i++;
	}
	get_z(fdf);
	return (0);
}
