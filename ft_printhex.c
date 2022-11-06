/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:54:57 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/06 10:07:52 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;
	
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
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
				ft_printchar(hex - 10 + 'A');
		}
	}
	return (len);
}
