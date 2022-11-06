/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:05:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/06 10:37:23 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		ft_putstr("(null)");
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
	int 	i;
	char 	ptr[12];
	int	len;

	i = 0;
	len = 0;
	while (n > 0)
	{
		ptr[i] = (n % 10) + 48;
		n /= 10;
		len++;
		i++;
	}
	while (i > 0)
	{
		write(1, &ptr[i], 1);
		i++;
	}
	return (len);

}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{	
		write(1, "-2147483648", 11);
		return (len + 11);
	}
	if (n == 0)
	{
		len++;
		write(1, "0", 1);
	}
	if (n < 0)
	{
		len++;
		n = -n;
		write(1, "-", 1);
	}
	len += ft_printnbr(n);
	return (len);
}
