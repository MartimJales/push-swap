/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:50:56 by mjales            #+#    #+#             */
/*   Updated: 2023/02/01 15:44:48 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	isinteger(char *s)
{
	int		i;
	long	num;

	i = 0;
	if (!ft_isdigit(s[i]) && s[i] != '-')
		return (0);
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	num = ft_atoi(s);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

int	arg_repeated(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i++ < argc - 1)
	{
		if (ft_strncmp(argv[i], argv[argc], ft_strlen(argv[i])) == 0 && \
		ft_strncmp(argv[i], argv[argc], ft_strlen(argv[argc])) == 0)
		{
			printf("%s == %s\n", argv[i], argv[argc]);
			return (1);
		}
	}
	return (0);
}

int	valid_input(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i++ < argc - 1)
	{
		if (!isinteger(argv[i]) || arg_repeated(i, argv))
		{
			printf("caiu com %s\n", argv[i]);
			return (0);
		}
	}
	return (1);
}
