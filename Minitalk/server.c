/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:10:16 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/29 19:16:50 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char	c = 0x00;
	static int				count = 0;
	static pid_t			client_pid = 0;

	(void)unused;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++count == 8)
	{
		count = 0;
		if (c == 0x00)
		{
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0x00;
		kill(client_pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill(client_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
