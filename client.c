/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:30:59 by abablil           #+#    #+#             */
/*   Updated: 2023/12/17 21:55:25 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_signal(int pid, unsigned char character)
{
    int i;
    unsigned char temp_char;

    i = 8;
    temp_char = character;
    while (i > 0)
    {
        i--;
        temp_char = character >> i;
        if (temp_char % 2 == 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(42);
    }
}
int main(int total, char **args)
{
    if (total == 3)
    {
        pid_t server_pid = ft_atoi(args[1]);
        char *str = args[2];
        int i = 0;
        while (str[i])
        {
            send_signal(server_pid, str[i]);
            i++;
        }
    }
    else
    {
        ft_printf("Usage: %s <server_PID> <message>\n", args[0]);
        return (-1);
    }
    return (0);
}