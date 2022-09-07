/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:50:56 by mjales            #+#    #+#             */
/*   Updated: 2022/09/07 11:50:56 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
	return (!(c < '0' || c > '9'));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	base;
	int	i;

	sign = 1;
	base = 0;
	i = 0;
	if (!str[0])
		return (0);
	while (str[i] >= '\t' && str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		base = (10 * base) + (str[i] - '0');
		i++;
	}
	return (base * sign);
}

int isinteger(char *s)
{
	int i;
	int num;

	i = 0;
	if (!ft_isdigit(s[i]) && s[i] != '-')
		return (0);
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	num = ft_atoi(s);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int valid_input(int argc, char* argv[])
{
	int	i;
	int result = 1;

	i = 0;
	while (i++ < argc - 1)
	{
		printf("%s\n", argv[i]);
		if (!isinteger(argv[i]))
			result = 0;
		printf("RESULT = %d\n", result);
	}

	return (result);
}

