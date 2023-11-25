/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:30:43 by amakela           #+#    #+#             */
/*   Updated: 2023/11/25 17:58:48 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long nb, int *count)
{
	if (nb == -2147483648)
		*count = ft_printstr("-2147483648");
	else if (nb < 0)
	{
		*count += ft_printchar('-');
		ft_printnbr(-nb, count);
	}
	else if (nb > 9)
	{
		ft_printnbr(nb / 10, count);
		ft_printnbr(nb % 10, count);
	}
	else
		*count += ft_printchar(nb + 48);
	return (*count);
}
