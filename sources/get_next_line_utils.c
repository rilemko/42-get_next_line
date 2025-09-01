/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:03:06 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/22 17:59:47 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (len--)
		*str++ = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
		if (s[index++] == (unsigned char) c)
			return ((char *) s + (index - 1));
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (*src && (dstsize-- - 1))
			*dst++ = *src++;
		ft_bzero(dst, 1);
	}
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strpos(const char *s, int c)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(s) + 1;
	index = 0;
	while (len--)
		if (s[index++] == (unsigned char) c)
			return (index - 1);
	return (0);
}
