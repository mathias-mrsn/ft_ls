#include "ft_ls.h"

static t_dir*
_create_file(const char* filename, t_dir* next, uint32_t type)
{
	t_dir*	new;

	new = NULL;
	new = (t_dir *)__malloc(sizeof(t_dir), DIR_STACK);
	new->_filename = filename;
	new->_next = next;
	new->_type = type;
	return (new);
}

t_boolean
add_file_back(t_dir **head, const char* filename, uint32_t type)
{
	t_dir* tmp;

	if (NULL == head)
		return (__FAILURE);
	tmp = (*head);
	if (NULL == tmp)
		(*head) = _create_file(filename, NULL, type);
	else
	{
		for ( ; NULL != tmp->_next; tmp = tmp->_next);
		tmp->_next = _create_file(filename, NULL, type);
	}
	return (__SUCCESS);
}

t_boolean
add_file_front(t_dir** head, const char* filename, uint32_t type)
{
	t_dir* tmp;

	if (NULL == head)
		return (__FAILURE);
	tmp = (*head);
	(*head) = _create_file(filename, ((NULL == tmp) ? NULL : tmp), type);
	return (__SUCCESS);
}
