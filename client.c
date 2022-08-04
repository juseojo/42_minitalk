/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 03:22:40 by seongjch          #+#    #+#             */
/*   Updated: 2022/08/05 07:09:18 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	free_exit(char **target, int num)
{
	free(*target);
	*target = 0;
	exit(num);
}

int	send_ending(char **target, int pid)
{
	int	i;

	i = 0;
	while (i != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			free_exit(target, 6);
		usleep(50);
		i++;
	}
	free_exit(target, 0);
	return (1);
}

int	send_bit(int pid, char *str)
{
	static int	stone_pid = 0;
	static int	bits = -1;
	static char	*letter = 0;

	if (str)
		letter = ft_strdup(str);
	if (!letter)
		exit(3);
	if (pid)
		stone_pid = pid;
	if (letter[++bits / 8])
	{
		if (letter[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(stone_pid, SIGUSR2) == -1)
				free_exit(&letter, 4);
		}
		else if (kill(stone_pid, SIGUSR1) == -1)
			free_exit(&letter, 5);
	}
	if (!letter[bits / 8])
		send_ending(&letter, stone_pid);
	usleep(50);
	return (1);
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		send_bit(0, 0);
	if (signum == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isallnum(argv[1]))
	{
		ft_printf("wrong arguments\n");
		exit(7);
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
