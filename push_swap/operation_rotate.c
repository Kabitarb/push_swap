#include "push_swap.h"

static void rotate(t_node **head)
{
    if(!head || !*head || (*head)->next == *head)
        return;
    *head = (*head)->next;
}

void ra(t_node **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_node **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}