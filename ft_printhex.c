/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:13 by amakela           #+#    #+#             */
/*   Updated: 2023/11/25 17:57:17 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long nb, char specifier, int *count)
{
	if (nb > 15)
	{
		ft_printhex(nb / 16, specifier, count);
		ft_printhex(nb % 16, specifier, count);
	}
	else if (nb < 10)
		*count += ft_printchar(nb + '0');
	else
	{
		if (specifier == 'x' || specifier == 'p')
			*count += ft_printchar(nb - 10 + 'a');
		if (specifier == 'X')
			*count += ft_printchar(nb - 10 + 'A');
	}
	return (*count);
}
