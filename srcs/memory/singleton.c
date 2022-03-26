/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:56:30 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/26 13:57:14 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls*
s (void)
{
	static t_ls* singleton = NULL;

	if (!singleton)
		singleton = __malloc(sizeof(t_ls), SINGLETON_STACK);
	return (singleton);
}