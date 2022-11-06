/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:00:50 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/06 10:56:53 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	p = 2;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		p += 1;	
		p += write(1, "0", 1);
		return (p);
	}
	else
	{
		ft_putptr(ptr);
		p += ft_ptrlen(ptr);
	}
	return (p);
}
