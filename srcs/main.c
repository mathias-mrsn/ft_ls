/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:57:10 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/26 14:11:58 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const struct s_option_internal	flags[] =
{
	{'a', "all", FLAG_A_MIN, false},
	{'R', "recursive", FLAG_R_MAJ, false},
	{'r', "reverse", FLAG_R_MIN, false},
	{'t', NULL, FLAG_T_MIN, false},
	{'l', NULL, FLAG_L_MIN, false},
	{0, NULL, 0, false}
};

/*	TO DELETE */

void
_print_specs(void)
{
	printf("FLAGS = [%llu]\n", s()->flags);
	printf("FILES = ");
	for (t_dir *tmp = s->head; tmp; tmp = tmp->next)
		printf("%s ", tmp->_filename);
}

/*	END	*/

static inline uint64_t
_is_correct_flag (char c)
{
	for (int i = 0; flags[i]._short_f; i++)
		if (flags[i]._short_f == c)
			return (flags[i]._bit);
	return (0);
}

int
parsing_files (t_ls* s, int ac, char** av, int i)
{
	DIR	*dir;

	for ( ; i < ac; i++)
	{
		dir = opendir(av[i]);
		if (!dir)
			ERRNO_ERR(av[i]); return (__FAILURE);
		else
			add_file_back(&s->dirs, av[i]);
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
			return (parsing_files(s, ac, av, i));
	}
	return (__SUCCESS);
}

int
main (int ac, char **av)
{
	t_ls*	ls = s();

	if (__FAILURE == parsing_flags(ls, ac, av))
		return (__clean_all(), EXIT_FAILURE);
	_print_specs();
	return (EXIT_SUCCESS);
}