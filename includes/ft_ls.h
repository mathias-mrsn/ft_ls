/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:01 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/29 18:24:48 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft.h"
#include <stdbool.h>
#include <libc.h> // to delete
#include <dirent.h>
#include <errno.h>

# define FLAGS_ALLOW	"arRtl"

# ifndef LS_DEBUG
#  define LS_DEBUG 1
# endif

# if defined(LS_DEBUG) && (LS_DEBUG == 1)
#  define ERROR_LOG() __dprintf(2, "ft_ls: error: %s %s:l%d\n", __funct__, __FILE__, __LINE__);
# else
#  define ERROR_LOG()
# endif

#define INVALID_FLAG(c) __dprintf(STDERR_FILENO, "ls : invalid option -- %c\nusage: ls [%s]\n", c, FLAGS_ALLOW);
#define ERRNO_ERR(s) __dprintf(STDERR_FILENO, "ls: %s: %s\n", s, strerror(errno));

struct	s_option_internal
{
	const char			_short_f;
	const char*			_long_f;
	const long			_bit;
	const t_boolean		_argument : 1;
};

typedef struct s_dir
{
	const char*			_filename;
	uint32_t		_type;
	struct s_dir*		_next;
}				t_dir;

enum
{
	FLAG_MINUS = (1ULL << 0),
	FLAG_AT = (1ULL << 1),

	FLAG_A_MAJ = (1ULL << 2),
	FLAG_B_MAJ = (1ULL << 3),
	FLAG_C_MAJ = (1ULL << 4),
	FLAG_F_MAJ = (1ULL << 5),
	FLAG_G_MAJ = (1ULL << 6),
	FLAG_H_MAJ = (1ULL << 7),
	FLAG_I_MAJ = (1ULL << 8),
	FLAG_L_MAJ = (1ULL << 9),
	FLAG_O_MAJ = (1ULL << 10),
	FLAG_P_MAJ = (1ULL << 11),
	FLAG_R_MAJ = (1ULL << 12),
	FLAG_S_MAJ = (1ULL << 13),
	FLAG_T_MAJ = (1ULL << 14),
	FLAG_U_MAJ = (1ULL << 15),
	FLAG_W_MAJ = (1ULL << 16),

	FLAG_A_MIN = (1ULL << 17),
	FLAG_B_MIN = (1ULL << 18),
	FLAG_C_MIN = (1ULL << 19),
	FLAG_D_MIN = (1ULL << 20),
	FLAG_E_MIN = (1ULL << 21),
	FLAG_F_MIN = (1ULL << 22),
	FLAG_G_MIN = (1ULL << 23),
	FLAG_H_MIN = (1ULL << 24),
	FLAG_I_MIN = (1ULL << 25),
	FLAG_K_MIN = (1ULL << 26),
	FLAG_L_MIN = (1ULL << 27),
	FLAG_M_MIN = (1ULL << 28),
	FLAG_N_MIN = (1ULL << 29),
	FLAG_O_MIN = (1ULL << 30),
	FLAG_P_MIN = (1ULL << 31),
	FLAG_Q_MIN = (1ULL << 32),
	FLAG_R_MIN = (1ULL << 33),
	FLAG_S_MIN = (1ULL << 34),
	FLAG_T_MIN = (1ULL << 35),
	FLAG_U_MIN = (1ULL << 36),
	FLAG_V_MIN = (1ULL << 37),
	FLAG_W_MIN = (1ULL << 38),
	FLAG_X_MIN = (1ULL << 39),
	FLAG_Y_MIN = (1ULL << 40),

	FLAG_ONE = (1ULL << 41),
	FLAG_PERCENT = (1ULL << 42),
	FLAG_COMMA = (1ULL << 43)
};

extern const struct s_option_internal	flags[];


typedef struct	s_ls
{
	uint64_t	flags;
	t_dir*		dirs;
}				t_ls;


#define SINGLETON_STACK	42
#define DIR_STACK		2

/*
**	FUNCTIONS
*/

t_ls*	s (void);

/*
**	LIST
*/

t_boolean
add_file_back(t_dir**, const char*, uint32_t);
t_boolean
add_file_front(t_dir**, const char*, uint32_t);

/*
**	PARSING
*/

int
parsing_flags (t_ls*, int, char**);

/*
**	DISPLAY
*/

int
recursive_ls (t_ls*, const char*);
int
ls_launcher (t_ls* s);

#endif