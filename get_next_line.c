/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:39:08 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/12 14:07:09 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcjoin(char *line, char *buffer, char c)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	i = ft_strchr(buffer, '\n') ?
		ft_strchr(buffer, '\n') - buffer : ft_strlen(buffer);
	if (!(new = (char *)malloc(ft_strlen(line) + i + 1)))
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (buffer[j] && buffer[j] != c)
	{
		new[i + j] = buffer[j];
		j++;
	}
	free(line);
	new[i + j] = 0;
	return (new);
}

static int		ft_taboulet(char **stat, char **line)
{
	char *tmp;

	tmp = *stat;
	if (*stat && *stat[0])
	{
		*line = ft_strcjoin(*line, *stat, '\n');
		*stat = ft_strchr(tmp, '\n') ?
			ft_strdup(ft_strchr(tmp, '\n') + 1) : NULL;
		ft_strdel(&tmp);
		if (*stat)
			return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			i;
	char		buffer[BUFF_SIZE + 1];
	static char	*stat = NULL;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (ft_taboulet(&stat, line) == 1)
		return (1);
	while ((i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			*line = ft_strcjoin(*line, buffer, '\n');
			stat = ft_strdup(ft_strchr(buffer, '\n') + 1);
			return (1);
		}
		*line = ft_strcjoin(*line, buffer, '\n');
	}
	if (!(*line))
		ft_strdel(&stat);
	return (*line ? 1 : i);
}
