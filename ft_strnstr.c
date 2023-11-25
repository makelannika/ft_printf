/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakela <amakela@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:02:00 by amakela           #+#    #+#             */
/*   Updated: 2023/11/24 12:09:35 by amakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return (ptr = (char *)haystack);
	if (len == 0)
		return (NULL);
	while ((haystack[i]) && (needle[j]) && (i < len))
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j ++;
			if (j == ft_strlen(needle))
				return (ptr = (char *)&haystack[i]);
		}
		j = 0;
		i ++;
	}
	if (j == ft_strlen(needle))
		return (ptr = (char *)&haystack[i - j]);
	return (0);
}
