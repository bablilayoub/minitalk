/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:30:59 by abablil           #+#    #+#             */
/*   Updated: 2023/12/22 15:21:12 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

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
		while (args[2][i])
		{
			send_signal(server_pid, args[2][i]);
			i++;
		}
	}
	else
		send_error_client("USAGE", "./client <server_PID> <message>");
	return (0);
}
