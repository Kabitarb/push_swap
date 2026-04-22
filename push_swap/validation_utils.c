#include "push_swap.h"

int error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int validate_chars(char *str)
{
	int i;
	
	i = 0;

	if(str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (error());
	while(str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (error());
		i++;
	}	
	return (0);
}

static int validate_number(char *str)
{
	long number;

	number = ft_atoi(str);
	if(number < INT_MIN || number > INT_MAX)
		return (error());
	return (0);
}

int validate(char **str)
{
	int i;

	i = 0;
	if(!str[i])
		return(error());

	while(str[i])
	{
		if (validate_chars(str[i]))
			return (1);
		if (validate_number(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int check_duplicate(t_node *head, int number)
{
	t_node *current;
	int flag;

	if(!head)
		return (0);
	
	current = head;
	flag = 1;
	while(current != head || flag)
	{
		flag = 0;
		if(current->data == number)
			return (error());
		current = current->next;
	}
	return(0);
}