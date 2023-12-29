/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:08:35 by abablil           #+#    #+#             */
/*   Updated: 2023/12/29 15:41:44 by abablil          ###   ########.fr       */
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

void	send_success(void)
{
	print_client();
	ft_printf("%s DONE %s Signal received from the server\n",
		BG_GREEN, WHITE);
}

void	send_error_client(char *type, char *str)
{
	print_client();
	ft_printf("%s %s %s %s\n", BG_RED, type, WHITE, str);
	exit(EXIT_FAILURE);
}
