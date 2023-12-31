/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:23:22 by abablil           #+#    #+#             */
/*   Updated: 2023/12/29 14:50:13 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "includes/ft_printf/ft_printf.h"
#include "includes/libft/libft.h"

#define BLUE "\033[0m\033[94m"
#define WHITE "\033[0m\033[97m"
#define LIGHT_BLUE "\033[0m\033[96m"
#define RED "\033[0m\033[91m"
#define GREEN "\033[0m\033[92m"
#define YELLOW "\033[0m\033[92m"

#define BG_BLUE "\033[30m\033[104m"
#define BG_LIGHT_BLUE "\033[30m\033[106m"
#define BG_RED "\033[30m\033[101m"
#define BG_GREEN "\033[30m\033[102m"
#define BG_YELLOW "\033[30m\033[103m"

void	print_client(void);
void	print_server(void);
void	send_success(void);
void	send_error_client(char *type, char *str);