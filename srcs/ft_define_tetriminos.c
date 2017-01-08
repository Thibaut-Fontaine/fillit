/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_tetriminos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:15:50 by tfontain          #+#    #+#             */
/*   Updated: 2016/12/12 19:50:51 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_block		g_pattern[19] = {
	{{{0, 0}, {0, 1}, {1, 0}, {1, 1}}},
	{{{0, 0}, {0, 1}, {0, 2}, {0, 3}}},
	{{{0, 0}, {1, 0}, {2, 0}, {3, 0}}},
	{{{0, 1}, {1, 0}, {1, 1}, {1, 2}}},
	{{{0, 0}, {0, 1}, {0, 2}, {1, 1}}},
	{{{0, 0}, {1, 0}, {1, 1}, {2, 0}}},
	{{{0, 1}, {1, 0}, {1, 1}, {2, 1}}},
	{{{0, 0}, {0, 1}, {1, 1}, {1, 2}}},
	{{{0, 1}, {0, 2}, {1, 0}, {1, 1}}},
	{{{0, 1}, {1, 0}, {1, 1}, {2, 0}}},
	{{{0, 0}, {1, 0}, {1, 1}, {2, 1}}},
	{{{0, 0}, {1, 0}, {2, 0}, {2, 1}}},
	{{{0, 1}, {1, 1}, {2, 0}, {2, 1}}},
	{{{0, 0}, {0, 1}, {1, 1}, {2, 1}}},
	{{{0, 0}, {0, 1}, {1, 0}, {2, 0}}},
	{{{0, 0}, {0, 1}, {0, 2}, {1, 2}}},
	{{{0, 0}, {0, 1}, {0, 2}, {1, 0}}},
	{{{0, 2}, {1, 0}, {1, 1}, {1, 2}}},
	{{{0, 0}, {1, 0}, {1, 1}, {1, 2}}}
};

/*
** square
** ---- >
** ---- ^
** -|- ^
** -|- v
** -|- >
** -|- <
** z
** z rev
** N
** N rev
** L
** L ret <-
** L rot <-
** L rev rot ->
** --| v
** |-- v
** --| ^
** |-- ^
*/
