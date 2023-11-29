/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:13 by amakela           #+#    #+#             */
/*   Updated: 2023/11/28 18:05:56 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long nbr, char specifier, int *count)
{
	if (nbr > 15)
	{
		if ((ft_printhex(nbr / 16, specifier, count) == -1)
			|| (ft_printhex(nbr % 16, specifier, count) == -1))
			return (-1);
	}
	else if (nbr < 10)
	{
		(*count)++;
		return (ft_printchar(nbr + '0'));
	}
	else
	{
		if (specifier == 'x' || specifier == 'p')
		{
			(*count)++;
			return (ft_printchar(nbr - 10 + 'a'));
		}
		else
		{
			(*count)++;
			return (ft_printchar(nbr - 10 + 'A'));
		}
	}
	return (*count);
}
