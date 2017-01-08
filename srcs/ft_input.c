/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:08:51 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/08 20:56:16 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

t_block			*ft_malloc_blocks(void)
{
	t_block		*blocks;

	if ((blocks = malloc(sizeof(t_block) * (MAX_TETRI + 1))) == NULL)
		ft_error();
	return (blocks);
}

t_block			ft_get_coordinates(char *str, t_block block)
{
	int			i;
	int			count_hash;

	i = 0;
	count_hash = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			block.array[count_hash].x = i % 5;
			block.array[count_hash].y = i / 5;
			++count_hash;
		}
		else if ((str[i] == '\n' && i != 4 && i != 9 && i != 14 && i != 19)
				|| (str[i] != '.' && str[i] != '\n'))
			ft_error();
		++i;
	}
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		ft_error();
	if (count_hash != 4)
		ft_error();
	return (block);
}

t_block			*ft_browse_file(t_block *blocks, int fd)
{
	char		buf[20];
	int			ret;
	int			i;

	ret = 1;
	i = 0;
	while (ret == 1)
	{
		if (ft_read_20(fd, buf) == 20)
		{
			blocks[i] = ft_get_coordinates(buf, blocks[i]);
			++i;
		}
		else
			ft_error();
		if ((ret = ft_read_1(fd, buf)) == 1)
		{
			if (*buf != '\n')
				ft_error();
		}
	}
	blocks[i].array[0].x = -1;
	blocks[i].array[0].y = -1;
	return (blocks);
}

t_block			*ft_input(int argc, const char *argv[])
{
	t_block		*blocks;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(EXIT_FAILURE);
	}
	blocks = ft_open_read_close_file(argv[1]);
	blocks = ft_decal(blocks);
	ft_compare(blocks);
	return (blocks);
}
