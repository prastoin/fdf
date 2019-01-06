/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:24:30 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/06 11:52:08 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static	int	ft_countdigits(char *str)
{
	int	i;
	int	count;
	int	nbspc;

	nbspc = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			nbspc++;
		if (str[i] == '-' || str[i] == '+' || ft_isdigit(str[i]) == 1)
		{
			count++;
			i++;
			while (ft_isdigit(str[i]) == 1)
				i++;
			i--;
		}
		i++;
	}
	printf("Nombre de digit = %d\n", count);
	printf("Nombre d espace = %d\n", nbspc);
	return (count);
}

static int	fill_tab(char **tab, char *line, int i)
{
	tab[i] = line;
	return (1);
}

static int	ft_fail_reading(char **tab, int i)
{
	tab[i + 1] = NULL;
//	freedbchar(tab);
	return (0);
}

static	int	ft_verif(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9' && str[i] != '-' && str[i] != '+' && str[i] != ' ')
			return (-1);
		if (((str[i] == '-') || (str[i] == '+')) && ((ft_isdigit(str[i + 1]) == 0) || (str[i - 1] != ' ')))
			return (-1);
//		if (str[i] == ' ' && (ft_isdigit(str[i + 1]) == 0 && (str[i + 1] != '+' || str[i + 1] != '-')))
//			return (-1);
		i++;
	}
	return (0);
}

int		parser(t_data *fdf)
{
	int		start;
	char			*line;
	char			*tab[2647];
	int				x;

	printf("ok\n");
	x = 0;
	start = 0;
	while (get_next_line(fdf->fd, &line) > 0)
	{
		if (start == 0)
			x = ft_countdigits(line);
		else if (line)
		{
			if ((ft_verif(line) != 0) || (ft_countdigits(line) != x))
				ft_fail_reading(tab, start);
			return (-1);
		}
		fill_tab(tab, line, start);
		start++;
	}
		tab[start] = NULL;
	return (0);
}
