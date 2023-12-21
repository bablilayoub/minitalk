/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:31:10 by abablil           #+#    #+#             */
/*   Updated: 2023/12/21 20:59:55 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	buff;
	static pid_t			new_pid;
	static pid_t			client_pid;
	static int				i;

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

void	print_server(void)
{
	ft_printf("%s   _____ __________ _    ____________ \n", LIGHT_BLUE);
	ft_printf("%s  / ___// ____/ __ \\ |  / / ____/ __ \\\n", LIGHT_BLUE);
	ft_printf("%s  \\__ \\/ __/ / /_/ / | / / __/ / /_/ /\n", LIGHT_BLUE);
	ft_printf("%s ___/ / /___/ _, _/| |/ / /___/ _, _/ \n", LIGHT_BLUE);
	ft_printf("%s/____/_____/_/ |_| |___/_____/_/ |_|  \n\n", LIGHT_BLUE);
	ft_printf("%s RUNNING %s The server is listening at PID: %s %d \n%s",
		BG_GREEN, WHITE, BG_GREEN, getpid(), WHITE);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handle_signal;
	action.sa_flags = SA_SIGINFO;
	print_server();
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		pause();
	return (0);
}
