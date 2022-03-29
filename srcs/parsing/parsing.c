/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:25:47 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/29 18:29:44 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline uint64_t
_is_correct_flag (char c)
{
	for (int i = 0; flags[i]._short_f; i++)
		if (flags[i]._short_f == c)
			return (flags[i]._bit);
	return (0);
}

static int
_parsing_files (t_ls* s, int ac, char** av, int i)
{
	DIR	*dir;

	for ( ; i < ac; i++)
	{
		dir = opendir(av[i]);
		if (!dir) {
			ERRNO_ERR(av[i]);
		}
		else
			add_file_back(&s->dirs, av[i], 0);
		if (dir)
			closedir(dir);
	}
	return (__SUCCESS);
}

int
parsing_flags (t_ls* s, int ac, char** av)
{
	uint64_t	bit;

	for (int i = 1; i < ac; i++)
	{
		if (av[i][0] == '-' && av[i][1])
		{
			for (int j = 1; av[i][j]; j++)
			{
				if ((bit = _is_correct_flag(av[i][j])))
					s->flags |= bit;
				else
				{
					INVALID_FLAG(av[i][j]);
					return (__FAILURE);
				}
			}
		}
		else
			return (_parsing_files(s, ac, av, i));
	}
	add_file_back(&s->dirs, ".", 8);
	return (__SUCCESS);
}
