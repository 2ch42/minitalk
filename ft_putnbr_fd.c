/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:47:57 by changhyl          #+#    #+#             */
/*   Updated: 2022/11/27 22:18:09 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	how_long(int var)
{
	int	count;

	count = 0;
	while (var > 0)
	{
		var /= 10;
		count++;
	}
	return (count);
}

static int	make_divide(int var)
{
	int	re_val;

	re_val = 1;
	while (var > 1)
	{
		var--;
		re_val *= 10;
	}
	return (re_val);
}

static void	print_result(int nb, int fd)
{
	int		length;
	int		div_val;
	char	c;

	length = how_long(nb);
	div_val = make_divide(length);
	while (length-- > 0)
	{
		c = '0' + nb / div_val;
		write(fd, &c, 1);
		nb = nb % div_val;
		div_val /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		print_result(n, fd);
	}
}
