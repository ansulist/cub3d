/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:15:56 by juhaamid          #+#    #+#             */
/*   Updated: 2024/03/07 17:44:48 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnndup(const char *src, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (0);
	while (i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_reading(int fd, char *text)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes = 1;
	while (!ft_strchrr(text, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		text = ft_strjoinn(text, buffer);
		if (text == NULL)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (text);
}

char	*line_by_line(char *text)
{
	int		i;

	i = 0;
	if (text[i] == '\0')
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	return (ft_strnndup(text, i + 1));
}

char	*modified_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	temp = ft_strdupp(str + i + 1);
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = ft_reading(fd, text);
	if (text == NULL)
		return (NULL);
	line = line_by_line(text);
	text = modified_line(text);
	return (line);
}
