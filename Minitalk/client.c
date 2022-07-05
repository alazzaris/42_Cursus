/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:10:21 by alazzari          #+#    #+#             */
/*   Updated: 2022/04/01 00:03:44 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_done(pid_t server_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		usleep(100);
		kill(server_pid, SIGUSR2);
	}
	exit(0);
}

void	send_bit(char *s, pid_t pid)
{
	static int				i = 8;
	static unsigned char	c;
	static char				*str;
	static pid_t			server_pid;

	if (s)
	{
		str = s;
		server_pid = pid;
		c = *str;
	}
	if (!i)
	{
		i = 8;
		c = *(++str);
		if (!c)
			ft_done(server_pid);
	}
	if (c && c >> --i & 0x01)
		kill(server_pid, SIGUSR1);
	else if (c)
		kill(server_pid, SIGUSR2);
	else if (!server_pid)
		ft_putstr_fd("Error: Wrong PID", 1);
}

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int	bytes = 0;

	(void)siginfo;
	(void)unused;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("\rThe message has been sent, bytes: ", 1);
		ft_putnbr_fd(++bytes, 1);
	}
	send_bit(0, 0);
}

int	ft_pid_isdigit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	e;

	if (argc != 3 || (!ft_pid_isdigit(argv[1])))
	{
		ft_putstr_fd("Wrong Input: ./client [PID] [Message]\n", 1);
		return (1);
	}
	if (!ft_strlen(argv[2]))
		exit(0);
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	ft_putstr_fd("Send Bytes   : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	send_bit(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
