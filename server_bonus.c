/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:00:31 by ahaloui           #+#    #+#             */
/*   Updated: 2023/01/12 11:35:52 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusers_handler(int sig, siginfo_t *info, void *context)
{
	static int				nbr_sh = 7;
	static pid_t			client_pid;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (info->si_pid != client_pid)
	{
		c = 0;
		nbr_sh = 7;
		client_pid = info->si_pid;
	}
	if (sig == SIGUSR2)
		c += (1 << nbr_sh);
	if (nbr_sh == 0)
	{
		if (c == 0)
			kill(client_pid, SIGUSR2);
		ft_putchar_fd(c, 1);
		nbr_sh = 7;
		c = 0;
	}
	else
		nbr_sh--;
}

int	main(void)
{
	struct sigaction	act;

	ft_putstr_fd("Proccess Id :", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	act.sa_sigaction = sigusers_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, 0) < 0)
		return (1);
	if (sigaction(SIGUSR2, &act, 0) < 0)
		return (1);
	while (1)
		pause();
}
