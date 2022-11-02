/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:18:26 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/02 19:56:28 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	va_list	args;

	i = 0;
	len = 0,
	
	va_start(ap);
	while (format[i] != '\0')
	{
		if (format[i] != '%') // means we wrote a sentence
		{
			write(1, &format[i], 1);
			len++;
		}
		else
		{
			i++;
			//do fct to check format
		}
		i++;		
	}
	va_end(ap);
	return (len);
}
// TODO PRINT_F
// 1. printf
// if %, j'écris %
// else va_arg
//
// va_arg va dans la fct which_args
// 2. if c,s,u,i,d,x,X,p
// redirect to correct fct
//
// 3. for each fct, check length, get arg, print arg.
// PRINTCHAR
// PRINTSTR
// PRINTNBR
// PRINTPTR
// PRINTUNSIGNED
// PRINTHEX
//
// Hex = 0123456789ABCDEF
// 	 101112131415161718191A1B1C1D1E1F
// 	 etc...
// 	 !! x with lowercase and X with uppercase !!
//
// Pointer = prefixed w/ x0 
// 	     something to do with unsigned long long
//
// RETURN VALUES
// printf returns an integer value, which is the total number of printed characters.
