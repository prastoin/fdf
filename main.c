/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/06 15:20:51 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int main(int argc, char **argv)
{
	t_data	fdf;

	if (argc == 2)
		fdf.fd = open(argv[1], O_RDONLY);
	else
		return(0);
	if (parser(&fdf) == -1)
	{
		ft_putstr("la map est invalide\n");
		return (0);
	}
		printf("la map est valide\n");
	data(&fdf);
	printf("les donnees on etaient traitee\n");
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < fdf.ord)
	{
		j = 0;
		while (j < fdf.ab)
		{
			printf("z[%d][%d] = %d\n", i, j, fdf.z[i][j]);
			j++;
		}
		i++;
	}
	return(0);
}
