/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavina <msavina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:28 by msavina           #+#    #+#             */
/*   Updated: 2023/11/17 19:32:33 by msavina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_from_file(int fd, char *stash);
char	*extract_line(char *stash);
char	*remove_line_read(char *stash);

char	*get_next_line(int fd)
{
	static char		*stash[FOPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash[fd] = read_from_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (line[0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (free(line), NULL);
	}
	stash[fd] = remove_line_read(stash[fd]);
	return (line);
}

char	*read_from_file(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(stash), NULL);
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*remove_line_read(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), (NULL));
	new_stash = (char *)ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	if (!new_stash)
		return (NULL);
	i++;
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	return (free(stash), new_stash);
}
