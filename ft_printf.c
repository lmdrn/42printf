/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:18:26 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/06 09:44:03 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_fmt(char format, va_list ap)
{
	int	len;
	
	len = 0;
	if (format == 'c')
		len = ft_printchar(va_arg(ap, int));
	else if (format == 's')
		len = ft_printstr(va_arg(ap, char*));
	else if (format == 'd' || format == 'i')
		len = ft_printnbr(va_arg(ap, int));
	else if (format == 'x' || format == 'X')
		len = ft_printhex(va_arg(ap, unsigned int), format, ft_hexlen(va_arg(ap, unsigned int)));
	else if (format == 'p')
		len = ft_printptr(va_arg(ap, unsigned long long));
	else if (format == 'u')
		len = ft_printuint(va_arg(ap, unsigned int));
	else if (format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len += ft_check_fmt(format[i + 1], args);
			i++;
		}
		else
			len +=	write(1, &format[i], 1);
		i++;		
	}
	va_end(args);
	return (len);
}

/*#include "ft_print_fcts.c"
int main(void)
{
	va_list	args = NULL;
	void *a = "hello";
	
	printf("Test1: original printf\n");
	printf("%p\n", a);
	printf("Test2: printchar\n");
	printf("%d\n", ft_printchar('a'));
	printf("Test3: my printf\n");
	ft_printf("%x", a);
	printf("\n");
	printf("Test4: check fmt fct\n");
	printf("%d\n", ft_check_fmt('a', args));
	printf("Test5: check hex count\n");
	//printf("%x\n", ft_hexlen(a));
}*/
// Pointer = prefixed w/ x0 
// 	     something to do with unsigned long long
//
// RETURN VALUES
// printf returns an integer value, which is the total number of printed characters.
