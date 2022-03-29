/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:06:37 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/29 19:15:04 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
print_file(const char* filename)
{
	// struct stat* stats;

	// __memset(stats, 0, sizeof(struct stat));
	// stat(filename, stats);
	__printf("filename = %s\n", filename);
	// printf("%d\n", stats->st_mode);
}

void
print_directory (t_ls* s, t_dir** dir)
{
	for ( t_dir* tmp = (*dir); tmp; tmp = tmp->_next)
	{
		print_file(tmp->_filename);
	}
}

int
recursive_ls (t_ls* s, const char* path)
{
	DIR* dir;
	t_dir*	current_dir;
	struct dirent	*dirent;

	current_dir = NULL;
	dir = opendir(path);
	if (!dir)
		return (__FAILURE);
		
	do {
		dirent = readdir(dir);
		if (dirent)
			add_file_back(&current_dir, dirent->d_name, dirent->d_type);
	} while (dirent);
	if (current_dir)
		print_directory(s, &current_dir);
	if (s->flags & FLAG_R_MAJ)
	{
		for (t_dir* tmp = current_dir; tmp; tmp = tmp->_next)
		{
			if (tmp->_type == 4 && strcmp(tmp->_filename, "..") && strcmp(tmp->_filename, "."))
				recursive_ls(s, __strjoin(__strjoin(path, "/"), tmp->_filename));
		}
	}
	return (__SUCCESS);
}

int
ls_launcher (t_ls* s)
{
	for (t_dir* list = s->dirs; list; list = list->_next)
	{
		recursive_ls(s, list->_filename);
	}
	return (__SUCCESS);
}