#include "push_swap.h"

static void freestr(char **str)
{
	int i;

	i = 0;

	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int fill_stack(char **str, t_node **a)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(check_duplicate(*a, ft_atoi(str[i])))
			return (1);
		append_node(a, ft_atoi(str[i]));
		i++;
	}
	return (0);
}

int parse(char **argv, t_node **s)
{
	int	i;
	char **str;

	i = 1;
	while(argv[i])
	{
		str = ft_split(argv[i], ' ');
		if(!str || !str[0])
			return (error());
		if(validate(str) || fill_stack(str, s))
		{
			freestr(str);
			return (1);
		}
		freestr(str);
		i++;
	}
	return (0);
}

void free_stack(t_node **head)
{
	t_node *current;
	t_node *next;

	if(!*head)
		return;

	current = (*head)->next;
	while(current != *head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*head);
	*head = NULL;
}