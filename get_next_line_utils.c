/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:47:27 by jofilipe          #+#    #+#             */
/*   Updated: 2023/02/09 14:53:49 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char		*memall;
	int			len;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	memall = malloc((len + 1) * sizeof(char));
	if (!memall)
		return (NULL);
	while (str1 && *(str1 + i))
	{
		*(memall + i) = *(str1 + i);
		i++;
	}
	while (str2 && *(str2 + j))
		*(memall + i++) = *(str2 + j++);
	*(memall + i) = '\0';
	return (memall);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != c && *str != '\0')
		str++;
	if (*str == '\0')
	{
		if (c != '\0')
			return (NULL);
		else
			return ((char *)str);
	}
	return ((char *)str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		area;
	int		i;

	area = nmemb * size;
	ptr = malloc(area);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (area))
		*(ptr + i++) = '\0';
	return ((void *)ptr);
}
