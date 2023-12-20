/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:51:32 by abablil           #+#    #+#             */
/*   Updated: 2023/12/20 21:08:19 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	update_values(struct s_info *info)
{
	info->client_pid = info->new_pid;
	info->send_back = 0;
	info->buff = 0;
	info->i = 0;
}

void	send_signal_back(pid_t client_pid, int *send_back)
{
	kill(client_pid, SIGUSR1);
	*send_back = 1;
}

void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	static struct s_info	info;

	(void)context;
	if (!info.client_pid)
		info.client_pid = siginfo->si_pid;
	info.new_pid = siginfo->si_pid;
	if (info.new_pid != info.client_pid)
		update_values(&info);
	if (!info.send_back)
		send_signal_back(info.new_pid, &info.send_back);
	info.buff |= (signal == SIGUSR1);
	info.i++;
	if (info.i == 8)
	{
		ft_printf("%c", info.buff);
		info.i = 0;
		info.buff = 0;
	}
	else
		info.buff <<= 1;
}

void	print_server(void)
{
	ft_printf("%s   _____ __________ _    ____________ \n", LIGHT_BLUE);
	ft_printf("%s  / ___// ____/ __ \\ |  / / ____/ __ \\\n", LIGHT_BLUE);
	ft_printf("%s  \\__ \\/ __/ / /_/ / | / / __/ / /_/ /\n", LIGHT_BLUE);
	ft_printf("%s ___/ / /___/ _, _/| |/ / /___/ _, _/ \n", LIGHT_BLUE);
	ft_printf("%s/____/_____/_/ |_| |___/_____/_/ |_|  \n\n", LIGHT_BLUE);
	ft_printf("%s RUNNING %s Server is listening at PID: %s %d \n%s",
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
