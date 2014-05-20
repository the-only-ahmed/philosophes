/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 23:33:25 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 12:05:19 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		check_death(int *health)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		if (health[i] <= 0)
			return (i);
		i++;
	}
	return (-1);
}

void	init_pos1(t_all *all, int i)
{
	if (i == 4)
	{
		all->point[i].x = 850;
		all->point[i].y = 730;
	}
	else if (i == 5)
	{
		all->point[i].x = 560;
		all->point[i].y = 730;
	}
	else if (i == 6)
	{
		all->point[i].x = 340;
		all->point[i].y = 480;
	}
	all->point[7].etat = 0;
	all->health[i] = MAX_LIFE;
	all->minus[i] = 0;
	all->point[i].etat = 0;
}

void	init_pos(t_all *all, int i)
{
	if (i == 0)
	{
		all->point[i].x = 410;
		all->point[i].y = 270;
	}
	else if (i == 1)
	{
		all->point[i].x = 700;
		all->point[i].y = 270;
	}
	else if (i == 2)
	{
		all->point[i].x = 990;
		all->point[i].y = 270;
	}
	else if (i == 3)
	{
		all->point[i].x = 1060;
		all->point[i].y = 480;
	}
	init_pos1(all, i);
}

void	init(t_all *all)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		if (!i)
			all->name[i] = ft_strdup("lincoln");
		else if (i == 1)
			all->name[i] = ft_strdup("ezio");
		else if (i == 2)
			all->name[i] = ft_strdup("philo");
		else if (i == 3)
			all->name[i] = ft_strdup("pikachu");
		else if (i == 4)
			all->name[i] = ft_strdup("kamini");
		else if (i == 5)
			all->name[i] = ft_strdup("voltaire");
		else
			all->name[i] = ft_strdup("dieu");
		all->sleep[i] = 0;
		all->action[i] = 0;
		all->reflec[i] = 0;
		init_pos(all, i);
		i++;
	}
}
