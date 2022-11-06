/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:05:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/06 10:39:33 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		write(1, "(null)", 6);
		return (6);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		ft_printchar('-');
		len++;
		if (n == -2147483648)
		{	
			write(1, "2147483648", 10);
			return (len + 10);
		}
		else
			ft_printnbr(n * (-1));
	}
	else if (n >= 0 && n <= 9)
	{
		ft_printchar(n + '0');
		len++;
	}
	else
	{
		ft_printnbr(n / 10);
		ft_printnbr(n % 10);
	}
	return (len);
}
