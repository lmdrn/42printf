/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:05:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/03 17:36:39 by lmedrano         ###   ########.fr       */
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

int	ft_hexlen(unsigned int hex)
{
	int	len;

	len = 0;
	while (hex != 0)
	{
		len++;
		hex /= 16;
	}
	return (len);
}

int	ft_printhex(unsigned int hex, char format, int len)
{
	if (hex == 0)
		return (write(1, "0", 1));
	if (hex >= 16)
	{
		ft_printhex((hex / 16), format, len);
		ft_printhex((hex % 16), format, len);
	}
	else
	{
		if (hex <= 9)
			ft_printchar(hex + 48);
		else 
		{
			if (format == 'x')
				ft_printchar(hex - 10 + 'a');
			if (format == 'X')
				ft_printchar(hex - 10 + 'a');
		}
	}
	return (len);
}

int	ft_ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else 
	{
		if (ptr <= 9)
			ft_printchar(ptr + 48);
		else
			ft_printchar(ptr - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	p;

	p = 0;
	p += write(1, "0x10", 4);
	printf("This is p: %d\n", p);
	if (ptr == 0)
		p += write(1, "0", 1);
	else
	{	
		ft_putptr(ptr);
		p += ft_ptrlen(ptr);
	}
	return (p);
}	
