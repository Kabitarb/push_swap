#include "push_swap.h"

static int max_int(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

static int calc_cost(int pos, int above_med, int size)
{
    if (above_med == 1)
        return (pos);
    return (size - pos);
}

static int combine_cost(t_node *current, int cost_a, int cost_b)
{
    if (current->above_med == 1 && current->target->above_med == 1)
       return(max_int(cost_a, cost_b));
    if (current->above_med == 0 && current->target->above_med == 0)
        return (max_int(cost_a, cost_b));
    return (cost_a + cost_b);
}

void get_cost(t_node *a, t_node *b)
{
    t_node *current;
    int size_a;
    int size_b;

    size_a = length(a);
    size_b = length(b);
    current = b;
    while(1)
    {
        current->cost = combine_cost(current,
                calc_cost(current->target->pos,
                current->target->above_med, size_a),
            calc_cost(current->pos, current->above_med, size_b));
        current = current->next;
        if (current ==b)
            break;
    }
}

t_node *find_cheapest(t_node *b)
{
    t_node *current;
    t_node *cheapest;

    if(!b)
        return (NULL);
    cheapest = b;
    current = b->next;
    while(current != b)
    {
        if (current->cost < cheapest ->cost)
            cheapest = current;
        current = current->next;
    }
    return (cheapest);
}