/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:55:22 by jcrescen          #+#    #+#             */
/*   Updated: 2023/02/15 14:27:51 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

static void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (i & (1 << bit))
		{
			usleep(100);
			kill(pid, SIGUSR1);
		}
		else
		{
			usleep(100);
			kill(pid, SIGUSR2);
		}
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Write: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
