/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:51:25 by abablil           #+#    #+#             */
/*   Updated: 2023/12/29 15:28:51 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	send_signal(int pid, char character)
{
	int				i;
	char			temp_char;

	i = 7;
	temp_char = character;
	while (i >= 0)
	{
		temp_char = (character >> i) & 1;
		if (temp_char == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				send_error_client("ERROR", "Failed to send signal");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				send_error_client("ERROR", "Failed to send signal");
		}
		usleep(500);
		i--;
	}
	return (1);
}

void	handle_signal(int sig)
{
	(void)sig;
	send_success();
}

int	main(int total, char **args)
{
	int		i;
	pid_t	server_pid;

	if (total == 3)
	{
		i = 0;
		server_pid = ft_atoi(args[1]);
		if (!server_pid)
			send_error_client("ERROR", "Invalid PID");
		if (!args[2][i])
			send_error_client("ERROR", "Message can't be empty");
		signal(SIGUSR1, &handle_signal);
		while (args[2][i])
		{
			send_signal(server_pid, args[2][i]);
			i++;
		}
		send_signal(server_pid, '\0');
	}
	else
		send_error_client("USAGE", "./client <server_PID> <message>");
	return (0);
}
