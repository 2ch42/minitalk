/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:30:49 by changhyl          #+#    #+#             */
/*   Updated: 2023/04/27 22:23:19 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	divider;

	divider = 128;
	while (divider > 0)
	{
		if (c/divider == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c %= divider;
		divider /= 2;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
	}
	else
		write(1, "Argc should be 3.\n", 19);
	return (0);
}
