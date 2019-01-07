/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:15:14 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/07 16:16:45 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

//ici le but est de traiter les donnees du parser dans x y z.

int		ft_numlen(int nb)
{
	int	count;
	int	num;

	count = 1;
	num = nb;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
//	printf("longeur num%d\n", count);
	return (count);
}

int		get_z(t_data *fdf)
{
	int		i;
	int		j;
	int		tmp;
	int		n;
	int		m;

	m = 0;
	n = 0;
	tmp = 0;
	j = 0;
	i = 0;
	while (fdf->tab[j])
	{
//		printf("%s\n", fdf->tab[j]);
		i = 0;
		n = 0;
		while (fdf->tab[j][i])
		{
//			printf("I ==%d\n", i);
			if (ft_isdigit(fdf->tab[j][i]) == 1 || fdf->tab[j][i] == '-' || fdf->tab[j][i] == '+')
			{
//				printf(" PLUS I%s\n", fdf->tab[j] + i);
				tmp = ft_atoi(fdf->tab[j] + i);
//				printf("tmp = %d\n", tmp);
				fdf->z[m][n] = tmp;
//				printf("z[%d][%d] = %d\n", m, n, fdf->z[m][n]);
				n++;
				i += ft_numlen(tmp);
			}
			else
				i++;
		}
		m++;
		j++;
	}
	return (0);
}

int		data(t_data *fdf)
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
	//	printf("go get_z\n");
	get_z(fdf);
	//	printf("went get_z\n");
	return (0);
}
