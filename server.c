/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:31:10 by abablil           #+#    #+#             */
/*   Updated: 2023/12/19 19:23:29 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int signal, siginfo_t *info, void *context)
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
	buff |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", buff);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}
void print_server()
{
	ft_printf("   _____ __________ _    ____________ \n");
	ft_printf("  / ___// ____/ __ \\ |  / / ____/ __ \\\n");
	ft_printf("  \\__ \\/ __/ / /_/ / | / / __/ / /_/ /\n");
	ft_printf(" ___/ / /___/ _, _/| |/ / /___/ _, _/ \n");
	ft_printf("/____/_____/_/ |_| |___/_____/_/ |_|  \n\n");
	ft_printf("\033[30m\033[102m RUNNING \033[0m \033[92mServer is listening at PID: \033[93m%d\n\033[97m", getpid());
}

int main(void)
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