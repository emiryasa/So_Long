/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:51:35 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/18 16:56:41 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_readline(int fd, char *temp)
{
	char	*buffer;
	int		error;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	error = 1;
	while (error != 0 && (!ft_strchr_gnl(temp)))
	{
		error = read(fd, buffer, BUFFER_SIZE);
		if (error == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[error] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*ft_before_next_line(char *stash)
{
	int		i;
	char	*to_return;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	to_return = malloc((sizeof(char) * (i + 2)));
	if (!to_return)
		return (NULL);
	ft_strcpy_gnl(to_return, stash, i + 1);
	return (to_return);
}

char	*ft_new_line(char *stash)
{
	int		i;
	char	*to_return ;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	to_return = (char *)malloc((sizeof(char) * (ft_strlen_gnl(stash) - i + 1)));
	if (!to_return)
		return (free(stash), NULL);
	i++;
	ft_strcpy_gnl(to_return, stash + i, ft_strlen_gnl(stash + i));
	free(stash);
	return (to_return);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_readline(fd, temp);
	if (!temp)
		return (NULL);
	str = ft_before_next_line(temp);
	temp = ft_new_line(temp);
	return (str);
}
