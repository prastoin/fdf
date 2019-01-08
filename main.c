/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/08 17:09:07 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		deal_key(int key, t_data *fdf)
{
	int	i;

	i = 0;
	printf("key =%d\n", key);
	if (key == KEY_LESS)
		fdf->zoom -= 5;
	if (key == KEY_PLUS)
		fdf->zoom += 5;
	if (key == KEY_UP)
		fdf->position_y += 15;
	if (key == KEY_DOWN)
		fdf->position_y -= 15;
	if (key == KEY_RIGHT)
		fdf->position_x += 15;
	if (key == KEY_LEFT)
		fdf->position_x -= 15;
	if (key == KEY_CTRL)
		exit (0);
	if (key == KEY_NUM6)
		fdf->hauteur++;
	if (key == KEY_NUM3)
		fdf->hauteur--;
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, 1000, 1000);
	fdf->img_ptr = (int *)mlx_get_data_addr(fdf->img, &i, &i, &i);
	algo(fdf, fdf->ab, fdf->ord);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	fdf;

	fdf.zoom = 53;
	fdf.position_x = 500;
	fdf.position_y = 300;
	fdf.hauteur = 1;
	if (argc == 2)
		fdf.fd = open(argv[1], O_RDONLY);
	else
		return(0);
	if (fdf.fd == -1)
		return (0);
	if (parser(&fdf) == -1)
	{
		ft_putstr("la map est invalide\n");
		return (0);
	}
	printf("la map est valide\n");
	data(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, "prastoin's fdf");
	fdf.img = mlx_new_image(fdf.mlx, 1000, 1000);
	fdf.img_ptr = (int *)mlx_get_data_addr(fdf.img, &argc, &argc, &argc);
	printf("les donnees on etaient traitee\n");
	algo(&fdf, fdf.ab, fdf.ord);
	mlx_key_hook(fdf.win, deal_key, &fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_loop(fdf.mlx);
	return(0);
}

//	int	k = -1;
//	while (fdf.tab[++k])
//		printf("RENDU parser.c \n%s\nRENDU FIN\n", fdf.tab[k]);

/*	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < fdf.ord)
	{
		j = 0;
		while (j < fdf.ab)
		{
			printf("%d ", fdf.z[i][j]);
			j++;
			if (j == fdf.ab)
				printf("\n");
		}
		i++;
	}*/

