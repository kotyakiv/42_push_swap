#include "push_swap.h"

int	full_sorted_a(t_list *a)
{
	int	temp;

	while (a)
	{
		temp = *((int *)a->content);
		a = a->next;
		if (a == NULL)
			break ;
		if (temp > *((int *)a->content))
			return (0);
	}
	return (1);
}

int	sorted_a(t_list *a)
{
	int	num;
	int modflag;
	t_list	*temp;
	
	modflag = 0;
	temp = a;
	while (a)
	{
		num = *((int *)temp->content);
		temp = temp->next;
		if (temp == NULL)
			break ;
		if (temp->next == NULL &&  *((int *)temp->content) > *((int *)a->content))
			return (0);
		if (num > *((int *)temp->content))
		{
			if (modflag)
				return (0);
			modflag = 1;
		}
	}
	return (1);
}
