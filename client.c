/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:30:59 by abablil           #+#    #+#             */
/*   Updated: 2023/12/19 15:57:32 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_client()
{
	ft_printf("   ________    ___________   ________\n");
	ft_printf("  / ____/ /   /  _/ ____/ | / /_  __/\n");
	ft_printf(" / /   / /    / // __/ /  |/ / / /   \n");
	ft_printf("/ /___/ /____/ // /___/ /|  / / /    \n");
	ft_printf("\\____/_____/___/_____/_/ |_/ /_/     \n\n");
}

int send_error(char *str)
{
	print_client();
	ft_printf("%s", str);
	return (-1);
}

int send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (send_error("\033[30m\033[101m ERROR \033[0m \033[96mFaild to send signal\n"));
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (send_error("\033[30m\033[101m ERROR \033[0m \033[96mFaild to send signal\n"));
		}
		usleep(80);
	}
	return (1);
}

int main(int total, char **args)
{
	if (total == 3)
	{
		int		i;
		char	*str;
		pid_t	server_pid;

		i = 0;
		str = args[2];
		server_pid = ft_atoi(args[1]);
		if (!server_pid)
			return(send_error("\033[30m\033[101m ERROR \033[0m \033[96mInvalide PID"));
		while (str[i])
		{
			if (send_signal(server_pid, str[i]) == -1)
				return (-1);
			i++;
		}
	}
	else
		return (send_error("\033[30m\033[103m USAGE \033[0m \033[96m./client <server_PID> <message>\n"));
	return (0);
}
