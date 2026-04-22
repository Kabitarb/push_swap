#include "push_swap.h"

static void reverse(t_node **head)
{
    if(!head || !*head || (*head)->next == *head)
        return;
    *head = (*head)->prev;
}

void rra(t_node **a)
{
    reverse(a);
    write(1, "rra\n", 4);
}

void rrb(t_node **b)
{
    reverse(b);
    write(1, "rrb\n", 4);
}

void rrr(t_node **a, t_node **b)
{
    reverse(a);
    reverse(b);
    write(1, "rrr\n", 4);
}