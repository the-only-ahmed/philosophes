/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 11:15:15 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/11 12:03:23 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		draw_stat2(t_all all, t_env *e, int *i)
{
	if (all.point[*i].etat == 1)
		mlx_string_put(e->mlx, e->win, all.point[*i].x, all.point[*i].y,
				BLUE, "Is eating");
	else if (all.point[*i].etat == 2)
		mlx_string_put(e->mlx, e->win, all.point[*i].x, all.point[*i].y,
				BLUE, "Is resting");
	else if (all.point[*i].etat == 3)
		mlx_string_put(e->mlx, e->win, all.point[*i].x, all.point[*i].y,
				BLUE, "Is thinking");
	else if (all.point[*i].etat == 4)
		mlx_string_put(e->mlx, e->win, all.point[*i].x, all.point[*i].y,
				YELLOW, "Is waiting");
	*i += 1;
}

void			draw_stat(t_all all, t_env *e, int x)
{
	int		i;
	int		color;
	char	*str;

	i = 0;
	while (i < 7)
		draw_stat2(all, e, &i);
	if (all.point[7].etat == 7)
	{
		str = ft_strdup("Now, it is time... To DAAAAAAAANCE ! ! !");
		color = GREEN;
	}
	else if (all.point[7].etat == -1)
	{
		str = ft_strjoin(all.name[x], " IS DEAD :'(");
		color = RED;
	}
	if (all.point[7].etat)
		mlx_string_put(e->mlx, e->win, (WIDTH / 2) - (ft_strlen(str) * 3),
				HEIGHT / 2, color, str);
	draw_percent(all, e);
}

void			draw_percent(t_all all, t_env *e)
{
	int		i;
	int		x;

	i = 0;
	while (i < 7)
	{
		x = all.health[i] * 100 / MAX_LIFE;
		mlx_string_put(e->mlx, e->win, all.point[i].x, all.point[i].y - 20,
				RED, ft_strjoin("LIFE : %", ft_itoa(x)));
		i++;
	}
}
