/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:51:32 by abablil           #+#    #+#             */
/*   Updated: 2023/12/29 15:31:03 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_if_all_done(char c, pid_t client_pid)
{
	if (c == '\0')
	{
		if (kill(client_pid, SIGUSR1) == -1)
			send_error_server("ERROR", "Faild to send signal to the client");
	}
}

void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	static int		i = 0;
	static char		buff = 0;
	static pid_t	client_pid = 0;
	pid_t			new_pid;

	(void)context;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	new_pid = siginfo->si_pid;
	if (new_pid != client_pid)
	{
		i = 0;
		buff = 0;
		client_pid = new_pid;
	}
	buff = (buff << 1) + (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		check_if_all_done(buff, client_pid);
		if (buff != '\0')
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
	ft_printf("%s RUNNING %s The server is listening at PID: %s %d \n%s",
		BG_GREEN, WHITE, BG_GREEN, getpid(), WHITE);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
