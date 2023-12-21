/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:30:59 by abablil           #+#    #+#             */
/*   Updated: 2023/12/21 22:04:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_client(void)
{
	ft_printf("%s   ________    ___________   ________\n", GREEN);
	ft_printf("%s  / ____/ /   /  _/ ____/ | / /_  __/\n", GREEN);
	ft_printf("%s / /   / /    / // __/ /  |/ / / /   \n", GREEN);
	ft_printf("%s/ /___/ /____/ // /___/ /|  / / /    \n", GREEN);
	ft_printf("%s\\____/_____/___/_____/_/ |_/ /_/     \n\n", GREEN);
}

int	send_error(char *type, char *str)
{
	print_client();
	ft_printf("%s %s %s %s\n", BG_RED, type, WHITE, str);
	exit(EXIT_FAILURE);
}

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
				send_error("ERROR", "Failed to send signal");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				send_error("ERROR", "Failed to send signal");
		}
		usleep(250);
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
			send_error("ERROR", "Invalid PID");
		if (!args[2][i])
			send_error("ERROR", "Message can't be empty");
		while (args[2][i])
		{
			send_signal(server_pid, args[2][i]);
			i++;
		}
	}
	else
		send_error("USAGE", "./client <server_PID> <message>");
	return (0);
}
