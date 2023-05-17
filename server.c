/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:30:49 by changhyl          #+#    #+#             */
/*   Updated: 2023/04/29 02:29:33 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_hand(int sig) 
{
	static int	i;
	static int	c;

	if (i < 8)
	{
		c *= 2;
		if (sig == SIGUSR2)
			c += 1;
		i++;
		if (i == 8)
		{
			write(1, &c, 1);
			i = 0;
			c = 0;
		}
		return ;
	}
}

int	main()
{
	struct sigaction	act;
	int					n;

	write(1, "SERVER PID : ", 14);
	n = getpid();
	ft_putnbr_fd(n, 1);
	write(1, "\n", 2);
	act.sa_handler=sig_hand;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if (sigaction(SIGUSR1, &act, 0) < 0 || sigaction(SIGUSR2, &act, 0) < 0)
	{
		write(1, "sigaction failed.", 18);
		return (0);
	}
	while (1)
	{
		pause();
	}
}
