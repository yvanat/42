/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:45:56 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/19 16:14:03 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		main(int argc, char **argv)
{
	pthread_t		philo[ft_atoi(argv[1])];
	int				i;
	t_thread		*thread;
	t_tvar			*var;

	if (argc < 5 || argc > 6 || init_struct(&thread, &var, argc, argv))
		return (-1);
	i = -1;
	gettimeofday(&(var->initial_time), NULL);
	while (++i < var->nb_philo)
	{
		thread[i].num_philo = i;
		thread[i].state = NEED_EAT;
		thread[i].var = var;
		thread[i].last_eat = var->initial_time;
		pthread_create(&philo[i], NULL, philosophers, thread + i);
	}
	i = -1;
	while (++i < var->nb_philo)
		pthread_join(philo[i], NULL);
	pthread_mutex_destroy(&(var->mutex_forks));
	free_ret(var->tab_eat, var->forks, var, thread);
	return (0);
}
