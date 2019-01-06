/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/06 11:44:07 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int main(int argc, char **argv)
{
	t_data fdf;
	if (argc == 2)
		fdf.fd = open(argv[1], O_RDONLY);
	else
	{
		ft_putstr("Error\n");
		return(0);
	}
	printf("ok\n");
	parser(&fdf);
	return(0);
}
