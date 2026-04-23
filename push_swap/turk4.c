#include "push_swap.h"

static void execute_move(t_node **a, t_node **b)
{
    t_node *cheapest;

    find_target (*a, *b);
    get_cost(*a, *b);
    cheapest = find_cheapest(*b);
    if(cheapest->above_med == 1 && cheapest->target->above_med == 1)
        rotate_both(a, b, cheapest);
    else if(cheapest->above_med == 0 && cheapest->target->above_med == 0)
        rev_rotate_both(a, b, cheapest);
    else
        rotate_diff(a, b, cheapest);
    pa(a, b);
}

static void push_to_a(t_node **a, t_node **b)
{
    while(*b)
        execute_move(a, b);
}

static void rotate_min(t_node **a)
{
    t_node *min_node;

    set_position(*a);
    min_node = min(*a);
    if(min_node->above_med == 1)
    {
        while(*a != min_node)
            ra(a);
    }
    else
    {
        while(*a != min_node)
            rra(a);
    }  
}

int is_sorted(t_node *a)
{
    t_node *current;

    if(!a)
        return (1);
    current = a;
    while(current->next != a)
    {
        if(current->data > current->next->data)
            return(0);
        current = current->next;
    }
    return (1);
}

void push_swap(t_node **a, t_node **b)
{
    if (is_sorted(*a))
        return;
    if (length (*a) == 2)
    {
        sa(a);
        return;
    }
    if(length (*a) == 3)
    {
        three_sort(a);
        return;
    }
    pushto_b(a, b);
    three_sort(a);
    push_to_a(a, b);
    rotate_min(a);
}
