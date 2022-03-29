/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:57:10 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/29 16:39:11 by mamaurai         ###   ########.fr       */
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
	for (t_dir *tmp = s()->dirs; tmp; tmp = tmp->_next)
		printf("%s ", tmp->_filename);
	printf("\n\n");
}

/*	END	*/



int
main (int ac, char **av)
{
	t_ls*	ls = s();

	if (__FAILURE == parsing_flags(ls, ac, av))
		return (__clean_all(), EXIT_FAILURE);
	_print_specs();
	ls_launcher(ls);
	return (EXIT_SUCCESS);
}