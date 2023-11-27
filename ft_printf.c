/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:16:29 by amakela           #+#    #+#             */
/*   Updated: 2023/11/27 21:03:09 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	read_format(const char *format, va_list args);
static int	check_specifier(va_list args, const char specifier);

int	ft_printf(const char *format, ...)
{
	int			ret;
	va_list		args;

	ret = 0;
	va_start(args, format);
	ret = read_format(format, args);
	va_end(args);
	return (ret);
}

static int	read_format(const char *format, va_list args)
{
	int	i;
	int	add;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			if (ft_printchar(format[i++]) == -1)
				return (-1);
			count++;
		}
		if (format[i] != '\0' && format[i++] == '%')
		{
			add = check_specifier(args, format[i++]);
			if (add == -1)
				return (-1);
			count += add;
		}
	}
	return (count);
}

static int	check_specifier(va_list args, const char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_printnbr(va_arg(args, int), &count));
	else if (specifier == 'u')
		return (ft_printnbr(va_arg(args, unsigned int), &count));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_printhex(va_arg(args, unsigned int), specifier, &count));
	else if (specifier == '%')
		return (ft_printchar('%'));
	else if (specifier == 'p')
	{
		if (ft_printstr("0x") == -1)
			return (-1);
		return ((ft_printhex(va_arg(args, unsigned long),
					specifier, &count) + 2));
	}
	if (ft_printchar(specifier) == -1)
		return (-1);
	return (1);
}
