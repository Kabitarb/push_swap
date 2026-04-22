#include "push_swap.h"

static void swap(t_node **head)
{
    int temp;

    if(!head || !*head || (*head)->next == *head)
        return;
    temp = (*head)->data;
    (*head)->data = (*head)->next->data;
    (*head)->next->data = temp;
}

void sa(t_node **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_node **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
