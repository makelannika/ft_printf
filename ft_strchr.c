/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:03:14 by amakela           #+#    #+#             */
/*   Updated: 2023/11/23 19:28:43 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	length;
	size_t	i;
	char	ch;

	i = 0;
	ch = (char)c;
	length = ft_strlen(s);
	while (i <= length)
		if (s[i] != ch)
			i++;
	else
		return ((char *)&s[i]);
	return (0);
}
