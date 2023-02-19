/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:24:29 by changhyl          #+#    #+#             */
/*   Updated: 2023/02/19 18:23:50 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	check_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	check_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		signal;
	char	*s;

	i = 0;
	result = 0;
	signal = 1;
	s = (char *)str;
	while (check_whitespace(*(s + i)) == 1)
		i++;
	if (*(s + i) == '-' || *(s + i) == '+')
	{
		if (*(s + i) == '-')
			signal *= -1;
		i++;
	}
	while (check_digit(*(s + i)) == 1)
	{
		result *= 10;
		result += (*(s + i) - 48);
		i++;
	}
	return (result * signal);
}
