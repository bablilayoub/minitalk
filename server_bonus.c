/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:51:32 by abablil           #+#    #+#             */
/*   Updated: 2023/12/22 15:17:10 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
	info.buff = (info.buff << 1) + (signal == SIGUSR1);
	info.i++;
	if (info.i == 8)
	{
		ft_printf("%c", info.buff);
		info.i = 0;
		info.buff = 0;
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
