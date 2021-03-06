/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:00:57 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/05 15:21:22 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float **ft_tab_objet(int nbr_objet,  char **map )
{
	int y; 
	int x;
	float **objet;

	y = 0;
	x = -1;
	objet = malloc(sizeof(float*) * (nbr_objet + 1));
	objet[nbr_objet] = NULL;
	while(0 != nbr_objet && map[y] != NULL)
	{
		if(map[y][++x] == '2')
		{
			objet[nbr_objet - 1] = malloc(sizeof(float) * 2);
			objet[nbr_objet - 1][0] = y + 0.5;
			objet[nbr_objet - 1][1] = x + 0.5;
			nbr_objet--;
		}
		else if(map[y][x] == '\0')
		{
		y++;
		x = -1;
		}
	}
	int i;
	i = -1;
//		while (objet[++i] != NULL)
//			printf("%f et %f\n", objet[i][0], objet[i][1]);
		return objet;
}
int		ft_size_map(char *tab)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (tab[++i] != '\0')
		if (tab[i] != ' ')
			n++;
	return (n);
}

void	ft_copy_map(char *tab, char *map)
{
	int	i;
	int	y;

	i = -1;
	y = 0;
	while (tab[++i] != '\0')
	{
		map[i] = tab[i];
	}
		map[i] = '\0';
}

char	**ft_malloc_struc_map(char **tab)
{
	int		i;
	int		y;
	char	**map;

	y = 0;
	i = -1;
	while (tab[++i][0] == '\0')
			;
	while (tab[i] !=  0 && tab[i++][0] !=  '\0')
		y++;
//	printf("%s\n",tab[i]);
//	printf("%s\n",tab[i+1]);
//	printf("%s\n",tab[i]);
//	printf("%s\n",tab[i+2]);

	if (tab[i] != 0 && tab[i + 1] != 0)
	{
		ft_error(2);
		return (NULL);
	}
	map = malloc(sizeof(char*) * (y + 1));
	map[y] = 0;
	y = 0;
	i = -1;
	while (tab[++i][0] == '\0')
		;
//		ft_printf("[%s]\n",tab[i]);

	while (tab[i] != 0 && tab[i][0] !=  '\0')
	{
		map[y++] = ft_strdup(tab[i]);
//		ft_printf("a=%s]\n",map[y-1]);
		i++;
	}
//		ft_printf("a=%s]\n",map[y]);
	return (tab);
}

void	ft_transition(char **tab, t_deb *deb)
{
	int		i;
	int		x;
	int		objet;
	x = 0;
	i = 0;
	objet = 0;
	while (tab[i] != NULL)
		i++;
	deb->map = malloc(sizeof(char*) * (i + 1));
	deb->map[i] = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		deb->map[i] = malloc(ft_strlen_cub(tab[i]) + 1);
		while (tab[i][x] != '\0')
		{
			deb->map[i][x] = tab[i][x];
			if (deb->map[i][x] == '2')
				objet++;
			x++;
		}
		deb->map[i][x] = '\0';
		x = 0;
		i++;
	}
		deb->objet = ft_tab_objet(objet, deb->map);
//		printf("objet = %d\n",objet);
	i = -1;
//		while (deb->objet[++i] != NULL)
//			printf("%f et %f\n", deb->objet[i][0], deb->objet[i][1]);
}

