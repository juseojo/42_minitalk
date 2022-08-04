/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 06:17:18 by seongjch          #+#    #+#             */
/*   Updated: 2022/08/05 07:11:01 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*addc(char *str, char c)
{
	char	*new_str;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_strdup(&c));
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new_str)
	{
		free(str);
		str = 0;
		return (NULL);
	}
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	free(str);
	str = 0;
	new_str[i++] = c;
	new_str[i] = '\0';
	return (new_str);
}

void	ending(char **letter, int pid)
{
	ft_printf("%s", *letter);
	free(*letter);
	*letter = 0;
	if (kill(pid, SIGUSR2) == -1)
		exit(1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*letter = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			letter = addc(letter, c);
		else
			ending(&letter, pid);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		exit(1);
}

int	main(void)
{
	struct sigaction	s_signal;
	sigset_t			masking;

	sigemptyset(&masking);
	sigaddset(&masking, SIGINT);
	sigaddset(&masking, SIGQUIT);
	s_signal.sa_handler = 0;
	s_signal.sa_flags = SA_SIGINFO;
	s_signal.sa_mask = masking;
	s_signal.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &s_signal, NULL);
	sigaction(SIGUSR2, &s_signal, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
}
