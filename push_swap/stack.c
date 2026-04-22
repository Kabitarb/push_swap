#include "push_swap.h"

t_node *create_node(int number)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if(!new_node)
        return (NULL);
    new_node->data = number;
    new_node->prev = new_node;
    new_node->next = new_node;
    return (new_node);
}

void append_node(t_node **head, int number)
{
    t_node *new_node;
	t_node *last;

    new_node = create_node(number);
	if(!new_node)
		return;
    if(!*head)
        *head = new_node;
    else
    {
        last = (*head)->prev;
        last->next = new_node;
        (*head)->prev = new_node;
        new_node->prev = last;
        new_node->next = *head;  
    }
}
