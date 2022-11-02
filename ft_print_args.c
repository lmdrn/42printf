/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:40:20 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/02 08:28:17 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(char *format, va_list ap)
{
	void	res;
	if (format == "%c")
		res = ft_putchar(va_arg(ap, char));
	else if (format == "%s")
		res = ft_putstr(va_arg(ap, char *));
	else if (format == "%p")
		// res = fct to print pointer;
	else if (format == "%d")
		res = ft_putnbr(va_arg(ap, int));
	else if (format == "%i")
		res = ft_putnbr(va_arg(ap, int));
	else if (format == "%u")
		res = ft_putnbr(va_arg(ap, int));
	else if (format == "%x")
		res = ft_putnbr(va_arg(ap, int));
	else if (format == "%X")
		res = ft_putnbr(va_arg(ap, int));
	else if (format == "%%")
		write(1, "%", 1);
	return (0);
}

