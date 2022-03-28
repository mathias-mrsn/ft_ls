#include "ft_ls.h"

static t_dir*
_create_file(const char* filename, t_dir* next)
{
	t_dir*	new;

	new = NULL;
	new = (t_dir *)__malloc(sizeof(t_dir), DIR_STACK);
	new->_filename = filename;
	new->_next = next;
	return (new);
}

t_boolean
add_file_back(t_dir **head, const char* filename)
{
	t_dir* tmp;

	if (NULL == head)
		return (__FAILURE);
	tmp = (*head);
	if (NULL == tmp)
		(*head) = create_file(filename, NULL);
	else
	{
		for ( ; NULL != tmp->next; tmp = tmp->next)
		tmp->next = create_file(filename, NULL);
	}
	return (__SUCCESS);
}

t_boolean
add_file_front(t_dir** head, const char* filename)
{
	t_dir* tmp;

	if (NULL == head)
		return (__FAILURE);
	tmp = (*head);
	(*head) = create_file(filename, ((NULL == tmp) ? NULL : tmp));
	return (__SUCCESS);
}