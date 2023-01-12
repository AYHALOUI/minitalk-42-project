/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:29:04 by ahaloui           #+#    #+#             */
/*   Updated: 2023/01/11 12:18:00 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	send_signals(int pid, char *str)
{
	unsigned int	i;
	int				nbr_sh;
	unsigned int	len;

	i = 0;
	nbr_sh = 8;
	len = ft_strlen(str);
	while (i <= len)
	{
		nbr_sh = 8;
		while (nbr_sh--)
		{
			if (str[i] & (1 << nbr_sh))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char *argv[])
{
	int	pid;

	if (argv[1])
		pid = ft_atoi(argv[1]);
	if (ac != 3 || !pid || pid == -1)
		return (1);
	send_signals(pid, argv[2]);
	return (0);
}
