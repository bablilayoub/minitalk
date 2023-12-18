/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:30:59 by abablil           #+#    #+#             */
/*   Updated: 2023/12/18 20:09:40 by abablil          ###   ########.fr       */
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
    ft_printf("   ________    ___________   ________\n");
    ft_printf("  / ____/ /   /  _/ ____/ | / /_  __/\n");
    ft_printf(" / /   / /    / // __/ /  |/ / / /   \n");
    ft_printf("/ /___/ /____/ // /___/ /|  / / /    \n");
    ft_printf("\\____/_____/___/_____/_/ |_/ /_/     \n\n");

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
        ft_printf("\033[30m\033[102m DONE \033[0m \033[92mMessage sent to server with PID: \033[93m%d \033[93m\n", server_pid);
    }
    else
    {
        ft_printf("\033[30m\033[103m USAGE \033[0m \033[96m%s <server_PID> <message>\n", args[0]);
        return (-1);
    }
    return (0);
}