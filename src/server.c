/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:46:02 by apodader          #+#    #+#             */
/*   Updated: 2023/07/10 15:02:52 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	handler_msg(int sig)
{
	static struct s_character	chr = {0, 0};

	if (sig == SIGUSR2)
		chr.character |= 1 << chr.current_bit;
	chr.current_bit++;
	if (chr.current_bit == 8)
	{
		ft_putchar_fd(chr.character, 1);
		chr.character = 0;
		chr.current_bit = 0;
	}
}

static void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

void	display_pid(void)
{
	pid_t	pid;
	char	*str_pid;

	pid = getpid();
	str_pid = ft_itoa(pid);
	ft_putendl_fd(str_pid, 1);
	free(str_pid);
}

int	main(void)
{
	display_pid();
	signal(SIGUSR1, handler_msg);
	signal(SIGUSR2, handler_msg);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
