/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:25:43 by amakela           #+#    #+#             */
/*   Updated: 2023/11/27 21:03:13 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(long nbr, int *count);
int		ft_printhex(unsigned long nbr, char specifier, int *count);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
