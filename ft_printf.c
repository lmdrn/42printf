/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:18:26 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/02 08:29:35 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			ft_print_args(format, ap);
		}
		i++;
	va_end(ap);
	return (0);
}

/* return (0) if success
 * return (1) if failed
 * */
