/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:31:10 by abablil           #+#    #+#             */
/*   Updated: 2023/12/29 14:58:47 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int		i = 0;
	static char		buff = 0;
	static pid_t	client_pid = 0;
	pid_t			new_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	new_pid = info->si_pid;
	if (new_pid != client_pid)
	{
		client_pid = new_pid;
		buff = 0;
		i = 0;
	}
	buff = (buff << 1) + (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", buff);
		i = 0;
		buff = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handle_signal;
	action.sa_flags = SA_SIGINFO;
	print_server();
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
