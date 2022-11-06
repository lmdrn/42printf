/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:46:15 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/06 10:08:31 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uintlen(unsigned int n)
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

char	*ft_uint_itoa(unsigned int n)
{
	char 	*nbr;
	int	len;

	len = ft_uintlen(n);
	nbr = (char*)malloc(sizeof(char) * (len + 1));
	if (nbr == NULL)
		return (NULL);
	nbr[len] = '\0';
	while (len > 0)
	{
		nbr[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (nbr);
}

int	ft_printuint(unsigned int n)
{
	int	len;
	char	*nbr;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		nbr = ft_uint_itoa(n);
		len += ft_printstr(nbr);
		free(nbr);
	}
	return (len);
}
