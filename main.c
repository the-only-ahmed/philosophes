/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:43:56 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 14:46:14 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_env	*main2(time_t *t, t_all *all)
{
	t_env		*e;

	init(all);
	e = init_mutex(all);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line),
			&(e->endian));
	*t = time(t) + TIMEOUT;
	draw(e);
	return (e);
}

void	main3(t_all *all, t_env *e, int a)
{
	if (a == -1)
		all->point[7].etat = 7;
	else
		all->point[7].etat = -1;
	draw(e);
	draw_stat(*all, e, a);
}

int		main(void)
{
	t_all		all;
	t_env		*e;
	time_t		t;
	time_t		x;
	int			i;
	int			a;

	e = main2(&t, &all);
	while (time(&x) < t && ((a = check_death(all.health)) == -1))
	{
		the_threads(&all);
		draw(e);
		draw_stat(all, e, -1);
		i = 0;
		while (i < 7)
		{
			pthread_join(all.philo[i], NULL);
			i++;
		}
	}
	main3(&all, e, a);
	e->all = &all;
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
