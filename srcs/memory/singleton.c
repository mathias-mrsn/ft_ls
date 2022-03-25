/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:56:30 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/25 17:04:43 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls*
s (void)
{
	static t_ls* singleton = NULL;

	if (!singleton)
		__malloc(sizeof(t_ls), SINGLETON_STACK);
	return (singleton);
}