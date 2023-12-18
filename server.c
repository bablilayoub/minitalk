/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:31:10 by abablil           #+#    #+#             */
/*   Updated: 2023/12/18 20:14:16 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int signal)
{
	static unsigned char buff;
	static int i;

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

int main(void)
{
	ft_printf("   _____ __________ _    ____________ \n");
	ft_printf("  / ___// ____/ __ \\ |  / / ____/ __ \\\n");
	ft_printf("  \\__ \\/ __/ / /_/ / | / / __/ / /_/ /\n");
	ft_printf(" ___/ / /___/ _, _/| |/ / /___/ _, _/ \n");
	ft_printf("/____/_____/_/ |_| |___/_____/_/ |_|  \n\n");
	ft_printf("\033[30m\033[102m RUNNING \033[0m \033[92mServer is listening at PID: \033[93m%d\n\033[97m", getpid());

	struct sigaction action;

	action.sa_handler = &handle_signal;
	action.sa_flags = 0;

	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);

	while (1)
		pause();

	return (0);
}