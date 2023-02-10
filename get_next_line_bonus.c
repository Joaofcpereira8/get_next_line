/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:43:50 by jofilipe          #+#    #+#             */
/*   Updated: 2023/02/10 13:45:33 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_next_line(char *str, int fd)
{
	char	*content_read;
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	content_read = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while ((bytes_read != 0) && !ft_strchr(content_read, '\n'))
	{
		bytes_read = read(fd, content_read, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (str)
				free (str);
			free (content_read);
			return (NULL);
		}
		content_read[bytes_read] = '\0';
		temp = ft_strjoin(str, content_read);
		free (str);
		str = temp;
	}
	free (content_read);
	return (str);
}

static char	*ft_clear_next_line(char *str)
{
	int		i;
	char	*linha;;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	linha = ft_calloc(sizeof(char), (i + 1 + 1));
	if (!linha)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		linha[i] = str[i];
		i++;
	}
	linha[i] = str[i];
	i++;
	linha[i] = '\0';
	/* free (str); */
	return (linha);
}

static char	*ft_get_the_next_line(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	temp = ft_calloc(sizeof(char), (ft_strlen(str) - i));
	if (!temp)
		return (NULL);
	i++;
	while (str[i] != '\0')
		temp[j++] = str[i++];
	free (str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		**mander;
	char		*linha;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read_next_line(*mander[fd], fd);
	if (!str)
		return (NULL);
	linha = ft_clear_next_line (str);
	str = ft_get_the_next_line (str);
	return (linha);
}

/* int	main(void)
{
	char	*str;
	int		i;
	int		fd;
	fd = open("text.txt", O_RDONLY);
	i = 1;
	while (i <= 15)
	{
		str = get_next_line(fd);
		printf("[%d]: %s", i, str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
} */
