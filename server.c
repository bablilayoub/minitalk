/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:31:10 by abablil           #+#    #+#             */
/*   Updated: 2023/12/17 20:28:40 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int signal)
{
	static unsigned char	buff;
	static int				i;

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

int main()
{
    ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR2, handle_signal);
	signal(SIGUSR1, handle_signal);
	while (1)
		pause();
	return (0);
}