#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *a;
	t_node *b;

	a = NULL; //to remove random garbage value
	b = NULL;
   	if(argc < 2)
   		return (0);
	if(parse (argv, &a))
	{
		free_stack(&a);
		return(1);
	}
	if(length(a) > 1)
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return(0);
}
