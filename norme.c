/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 04:05:26 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 12:18:28 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_env	*init_mutex(t_all *all)
{
	int		i;
	t_env	*e;

	i = 0;
	while (i < 7)
	{
		pthread_mutex_init(&(all->baguette[i]), NULL);
		pthread_mutex_init(&(all->ph[i]), NULL);
		i++;
	}
	e = (t_env*)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "philosophes 2D");
	return (e);
}

void	thread2(t_all **all, int i)
{
	time_t		p;
	time_t		x;

	p = time(&p);
	if (!(*all)->minus[i])
		(*all)->minus[i] = p;
	if ((x = p - (*all)->minus[i]) >= 1)
		(*all)->minus[i] = p;
	(*all)->health[i] -= x;
}

void	the_threads(t_all *all)
{
	int			i;

	i = 0;
	while (i < 7)
	{
		usleep(200);
		all->current = i;
		pthread_create(&(all->philo[i]), NULL, eat, (void*)all);
		pthread_create(&(all->philo[i]), NULL, rest, (void*)all);
		if (all->health[i] != MAX_LIFE)
			pthread_create(&(all->philo[i]), NULL, eat, (void*)all);
		pthread_create(&(all->philo[i]), NULL, think, (void*)all);
		if (all->health[i] != MAX_LIFE)
			pthread_create(&(all->philo[i]), NULL, eat, (void*)all);
		if (!all->action[i])
			thread2(&all, i);
		else
			all->minus[i] = 0;
		i++;
	}
}
