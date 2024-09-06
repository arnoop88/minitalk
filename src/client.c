/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:41:43 by apodader          #+#    #+#             */
/*   Updated: 2024/09/06 20:41:47 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_message(int pid, char *str)
{
	int	i;
	int	current_bit;

	i = 0;
	while (str[i])
	{
		current_bit = 0;
		while (current_bit < 8)
		{
			if (str[i] & (1 << current_bit))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(DELAY);
			current_bit++;
		}
		i++;
	}
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (1);
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
	{
		ft_putendl_fd("Invalid arguments\nUsage: ./client [server_pid] [message]", 1);
		return (0);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
