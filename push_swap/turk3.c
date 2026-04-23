#include "push_swap.h"

void set_position(t_node *stack)
{
    int index;
    t_node *current;
    int size;

    if(!stack)
        return;
    size = length(stack);
    index = 0;
    current = stack;
    while(1)
    {
        current ->pos = index;
        if (index < size / 2)
            current->above_med = 1;
        else
            current->above_med = 0;
        index++;
        current = current->next;
        if(current == stack)
            break;
    }
}

void find_target(t_node*a, t_node *b)
{
    t_node *current;

    set_position(a);
    set_position(b);
    current = b;
    while(1)
    {
        current->target = smallest_bigger(a, current);
        current = current->next;

        if(current == b)
            break;
    }
}

void rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
    while(*b != cheapest && *a != cheapest -> target)
        rr(a,b);
    while(*b != cheapest)
        rb(b);
    while(*a != cheapest->target)
        ra(a);
}

void rev_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
    while(*b != cheapest && *a != cheapest -> target)
        rrr(a,b);
    while(*b != cheapest)
        rrb(b);
    while(*a != cheapest->target)
        rra(a);

}

void rotate_diff(t_node **a, t_node **b, t_node *cheapest)
{
    if(cheapest->above_med == 1 && cheapest->target->above_med == 0)
    {
        while(*b != cheapest)
            rb(b);
        while(*a != cheapest -> target)
            rra(a);
    }
    else
    {
        while(*b != cheapest)
            rrb(b);
        while(*a != cheapest ->target)
            ra (a);
    }
}
