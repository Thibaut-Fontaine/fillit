/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:12:22 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/05 03:29:28 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Allowed functions :
**			exit, open, close, write, read, malloc et free
*/
#ifndef HEADER_H
# define HEADER_H
# include "../libft_files/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define MAX_TETRI 26

typedef struct	s_coord
{
	int			y;
	int			x;
}				t_coord;

typedef struct	s_block
{
	t_coord		array[4];
}				t_block;

t_block			*ft_input(int argc, const char *argv[]);
void			ft_print_result(t_block *blocks, t_coord *pos, size_t size);
void			ft_error(void);
t_block			*ft_open_read_close_file(const char filename[]);
int				ft_open_file(const char filename[]);
int				ft_read_20(int fd, char *buf);
int				ft_read_1(int fd, char *buf);
void			ft_close_file(int fd);
t_block			*ft_malloc_blocks(void);
t_block			*ft_browse_file(t_block *blocks, int fd);
void			ft_compare(t_block *blocks);
t_block			*ft_decal(t_block *blocks);

t_block			g_pattern[19];
void			ft_try_blocksize(t_block *blocks);

#endif
