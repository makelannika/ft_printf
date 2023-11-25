/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:16:29 by amakela           #+#    #+#             */
/*   Updated: 2023/11/25 18:02:26 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_incorrect_specifiers(const char *format);
static int	check_specifier(va_list args, const char specifier);

int	ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	va_list		args;

	if (!format)
		return (-1);
	if (check_incorrect_specifiers(format) == -1)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			count += ft_printchar(format[i++]);
		if (format[i] == '%')
		{
			i++;
			count += check_specifier(args, format[i++]);
		}
	}
	va_end(args);
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
		ft_printstr("0x");
		return ((ft_printhex(va_arg(args, unsigned long), specifier, &count) + 2));
	}
	return (0);
}

static int	check_incorrect_specifiers(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			i++;
		if (format[i++] == '%')
		{
			if (ft_strchr("cspdiuxX%", format[i++]) == 0)
				return (-1);
		}
	}
	return (0);
}
