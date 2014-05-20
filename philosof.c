/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 21:10:42 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 12:02:50 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat2(t_all **all, int x, int right)
{
	pthread_mutex_lock(&((*all)->ph[x]));
	(*all)->action[x] = 1;
	(*all)->point[x].etat = 1;
	usleep(SECOND * EAT_T);
	(*all)->health[x] = MAX_LIFE;
	(*all)->sleep[x] = 0;
	pthread_mutex_unlock(&((*all)->baguette[x]));
	pthread_mutex_unlock(&((*all)->baguette[right]));
	pthread_mutex_unlock(&((*all)->ph[x]));
}

void	*eat(void *thread)
{
	t_all	*all;
	int		right;
	int		a;
	int		b;
	int		x;

	all = (t_all*)thread;
	right = (all->current == 6) ? 0 : all->current + 1;
	if (!(a = pthread_mutex_trylock(&(all->baguette[all->current]))) &&
			!(b = pthread_mutex_trylock(&(all->baguette[right])))
			&& !all->reflec[right])
	{
		x = all->current;
		eat2(&all, x, right);
		all->action[x] = 0;
		all->point[x].etat = 4;
	}
	else if (!a || !b)
	{
		if (!a)
			pthread_mutex_unlock(&(all->baguette[all->current]));
		if (!b)
			pthread_mutex_unlock(&(all->baguette[right]));
	}
	return (NULL);
}

void	*rest(void *thread)
{
	t_all	*all;
	int		x;

	all = (t_all *)thread;
	if ((!all->sleep[all->current]) &&
			!pthread_mutex_trylock(&(all->ph[all->current])))
	{
		x = all->current;
		all->health[x] -= REST_T;
		all->action[x] = 1;
		all->point[x].etat = 2;
		usleep(SECOND * REST_T);
		all->sleep[x] = 1;
		pthread_mutex_unlock(&(all->ph[x]));
		all->action[x] = 0;
		all->point[x].etat = 4;
	}
	return (NULL);
}

void	think2(t_all **all, int b, int x, int right)
{
	if (!b)
		pthread_mutex_unlock(&((*all)->baguette[x]));
	else
		pthread_mutex_unlock(&((*all)->baguette[right]));
	(*all)->point[x].etat = 3;
	(*all)->health[x] -= THINK_T;
	(*all)->action[x] = 1;
	(*all)->reflec[x] = 1;
	usleep(SECOND * THINK_T);
	(*all)->sleep[x] = 0;
	pthread_mutex_unlock(&((*all)->ph[x]));
	(*all)->reflec[x] = 0;
	(*all)->action[x] = 0;
	(*all)->point[x].etat = 4;
}

void	*think(void *thread)
{
	t_all	*all;
	int		right;
	int		a;
	int		b;
	int		c;
	int		x;

	all = (t_all *)thread;
	right = (all->current == 6) ? 0 : all->current + 1;
	if (!(a = pthread_mutex_trylock(&(all->ph[all->current]))) &&
		(!(b = pthread_mutex_trylock(&(all->baguette[all->current]))) ||
		(!(c = pthread_mutex_trylock(&(all->baguette[right]))))))
	{
		x = all->current;
		think2(&all, b, x, right);
	}
	else
	{
		if (!a)
			pthread_mutex_unlock(&(all->ph[all->current]));
		if (!b)
			pthread_mutex_unlock(&(all->baguette[all->current]));
	}
	return (NULL);
}
