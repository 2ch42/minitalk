/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:30:49 by changhyl          #+#    #+#             */
/*   Updated: 2023/02/17 20:42:18 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_1(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "0", 1);
	}		
}

void	sig_2(int sig)l
{
	if (sig == SIGUSR2)
	{
		write(1, "1", 1);
	}
}

int	main(int argc, char *argv[])
{
	pid_t				p_id;
	struct sigaction	act1;
	struct sigaction	act2;
	int					i;

	act1.sa_handler=sig_1;
	act2.sa_handler=sig_2;
	sigemptyset(&act1.sa_mask);
	sigempytset(&act2.sa_mask);
	act1.sa_flags=0;
	act2.sa_flags=0;
	sigaction(SIGUSR1, &sig_1, 0);
	sigaction(SIGUSR2, &sig_2, 0);
	p_id = getpid();
	ft_putnbr(1, pid_t);
	i = 0;
	while (i < 8)
	{
		
	}
}
