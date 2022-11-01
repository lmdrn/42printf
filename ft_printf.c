/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:18:26 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/01 16:40:33 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_what_types(const char *format, ...)
{

	va_list ap;
	va_list ap2;
	int 	d;
	char	c;
	char 	*s;

	va_start(ap, format);
	va_copy(ap2, ap);
	while (*format)
	{
		if (format == c)
			c = va_arg(ap, int);
		else if (format == s)
			s = va_arg(ap, char *);
		else if ( format == d)
			d = va_arg(ap, int);
	}
	va_end(ap);
	va_end(ap2);
}

int	ft_printf(const char *format, ...)
{
	ft_what_types(format, ...);
	return (i);
}

//CHECK WHAT TYPES OG ARGS (STRING, FUNCTION, ETC...)
//CHECK WHAT TYPE OF FORMAT
//THEN REDIRECT TO FUNCTION DEALING WITH SPECIFIC FORMAT
//DO CONVERSION
//WRITE RESULTSi
//
//
//
int main (void)
{

	ft_printf ("%d", i);

}
