/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:55:03 by ahaloui           #+#    #+#             */
/*   Updated: 2023/01/07 12:38:02 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_white_space(char c)
{
	if ((c >= '\t' && c <= '\r' ) || c == ' ' )
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	signe;
	int	result;

	result = 0;
	signe = 1;
	while (is_white_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (10 * result) + *str - '0';
		str++;
	}
	return (result * signe);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		rest;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	rest = nbr % 10 + '0';
	nbr /= 10;
	if (nbr != 0)
		ft_putnbr_fd(nbr, fd);
	write(fd, &rest, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
