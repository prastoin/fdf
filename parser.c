/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:24:30 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/10 10:38:27 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static	int		ft_countdigits(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
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
	return (count);
}

static int		fill_tab(char **tab, char *line, int i)
{
	tab[i] = line;
	return (1);
}

static int		ft_fail_reading(char **tab, int i)
{
	tab[i] = NULL;
	ft_freedbchar(tab);
	return (0);
}

int				ft_verif(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] != '-' && str[i] != '+' && str[i] != ' ')
				return (-1);
		}
		if (((str[i] == '-') || (str[i] == '+')) &&
				((ft_isdigit(str[i + 1]) == 0)
				|| ((str[i - 1] != ' ' && i != 0))))
			return (-1);
		i++;
	}
	return (0);
}

int				parser(t_data *fdf, int i)
{
	char	*line;

	if (!(fdf->tab = (char **)malloc(sizeof(char *) * (fdf->ord + 1))))
		return (-1);
	fdf->ab = 0;
	while (get_next_line(fdf->fd, &line) > 0)
	{
		if (i == 0)
			fdf->ab = ft_countdigits(line);
		else if (i > 0)
		{
			if ((ft_verif(line) != 0) || (ft_countdigits(line) != fdf->ab))
			{
				if (line != NULL)
					free(line);
				ft_fail_reading(fdf->tab, i);
				return (-1);
			}
		}
		fill_tab(fdf->tab, line, i);
		i++;
	}
	fdf->tab[fdf->ord] = NULL;
	return (0);
}
