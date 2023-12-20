/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:51:25 by abablil           #+#    #+#             */
/*   Updated: 2023/12/20 17:58:49 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_client(void)
{
	ft_printf("%s   ________    ___________   ________\n", GREEN);
	ft_printf("%s  / ____/ /   /  _/ ____/ | / /_  __/\n", GREEN);
	ft_printf("%s / /   / /    / // __/ /  |/ / / /   \n", GREEN);
	ft_printf("%s/ /___/ /____/ // /___/ /|  / / /    \n", GREEN);
	ft_printf("%s\\____/_____/___/_____/_/ |_/ /_/     \n\n", GREEN);
}

int	send_error(char *str)
{
	print_client();
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

int	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;
	char			*faild;

	i = 8;
	temp_char = character;
	faild = "\033[30m\033[101m ERROR \033[0m\033[97m Faild to send signal\n";
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				send_error(faild);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				send_error(faild);
		}
		usleep(100);
	}
	return (1);
}

void	send_message(int sig)
{
	(void)sig;
	print_client();
	ft_printf("%s DONE %s Message recived from server\n", BG_GREEN, WHITE);
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
			send_error("\033[30m\033[101m ERROR \033[0m\033[97m Invalide PID");
		signal(SIGUSR1, &send_message);
		while (args[2][i])
		{
			send_signal(server_pid, args[2][i]);
			i++;
		}
	}
	else
	{
		print_client();
		ft_printf("%s USAGE %s ./client <server_PID> <message>\n",
			BG_RED, WHITE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
