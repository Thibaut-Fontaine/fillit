/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 03:56:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/08 20:52:36 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_open_file(const char filename[])
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("./fillit: ");
		ft_putstr(filename);
		ft_putstr(": No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int				ft_read_20(int fd, char *buf)
{
	int			ret;

	if ((ret = read(fd, buf, 20)) == -1)
		ft_error();
	return (ret);
}

int				ft_read_1(int fd, char *buf)
{
	int			ret;

	if ((ret = read(fd, buf, 1)) == -1)
		ft_error();
	return (ret);
}

void			ft_close_file(int fd)
{
	int			ret;

	ret = close(fd);
	if (ret == -1)
		ft_error();
}

t_block			*ft_open_read_close_file(const char filename[])
{
	t_block		*blocks;
	int			fd;

	blocks = ft_malloc_blocks();
	fd = ft_open_file(filename);
	blocks = ft_browse_file(blocks, fd);
	ft_close_file(fd);
	return (blocks);
}
