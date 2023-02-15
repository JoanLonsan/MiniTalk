/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:20:30 by ajordan-          #+#    #+#             */
/*   Updated: 2023/02/15 14:41:38 by jcrescen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received ✔️\n");
	else
		ft_printf("Message received ✔️\n");
}

static void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (i & (1 << bit))
		{
			usleep(300);
			kill(pid, SIGUSR1);
		}
		else
		{
			usleep(300);
			kill(pid, SIGUSR2);
		}
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			signal(SIGUSR1, ft_confirm);
			signal(SIGUSR2, ft_confirm);
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format.\n");
		ft_printf("Write: ./client_bonus [PID] [MESSAGE]\n");
		return (1);
	}
	return (0);
}
