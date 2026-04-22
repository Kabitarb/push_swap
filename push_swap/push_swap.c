#include "push_swap.h"

void push_swap(t_node **a, t_node **b)
{
	if(count(*a) == 2)
	{
		ra(a);
		return;
	}
	if(count(*a) == 3)
	{
		three_sort(a);
		return;
	}

	pushto_b(a, b);
	three_sort(a);
	
}

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
	free_stack(&a);
	free_stack(&b);
	return(0);
}

// int main(int argc, char **argv)
// {
//     t_node  *a;
//     t_node  *b;
//     t_node  *current;

//     a = NULL;
//     b = NULL;
//     if (argc < 2)
//         return (0);
//     if (parse(argv, &a))
//     {
//         free_stack(&a);
//         return (1);
//     }
//     printf("before:\n");
//     current = a;
//     while (current)
//     {
//         printf("%d\n", current->data);
//         current = current->next;
//         if (current == a)
//             break ;
//     }
//     pushto_b(&a, &b);
//     three_sort(&a);
//     printf("after sort_three:\n");
//     current = a;
//     while (current)
//     {
//         printf("%d\n", current->data);
//         current = current->next;
//         if (current == a)
//             break ;
//     }
//     printf("stack b:\n");
//     current = b;
//     while (current)
//     {
//         printf("%d\n", current->data);
//         current = current->next;
//         if (current == b)
//             break ;
//     }
//     free_stack(&a);
//     free_stack(&b);
//     return (0);
// }