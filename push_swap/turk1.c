#include "push_swap.h"

int length(t_node *stack)
{
    int count;
    t_node *current;

    if(!stack)
        return(0);

    count = 1;
    current = stack->next;

    while(current != stack)
    {
        count++;
        current = current->next;
    }
    return (count);
}

void pushto_b(t_node **a, t_node **b)
{
    int size;

    size = length(*a);
    while(size > 3)
    {
        pb(a, b);
        size--;
    }
}

t_node *min(t_node *a)
{
    t_node *mini;
    t_node *current;

    mini = a;
    current = a->next;
    while(current != a)
    {
        if(current->data < mini->data)
            mini = current;
        current = current->next;
    }
    return(mini);
}

static t_node *max(t_node *a)
{
    t_node *high;
    t_node *current;

    high = a;
    current = a->next;
    while(current != a)
    {
        if(current->data > high->data)
            high = current;
        current = current->next;
    }
    return (high);
}

t_node *smallest_bigger(t_node *a, t_node *b)
{
    t_node *current;
    t_node *min_node;
    t_node *target;
    int flag;

    current = a;
    min_node = min(a);
    target = max(a);
    flag = 1;

    if(min_node->data > b->data)
        return (min_node);

    while(current != a || flag)
    {
        flag = 0;
        if(current->data < target->data && current->data > b->data)
            target = current;
        current = current->next;
    }
    if(target->data < b->data)
        return(min_node);
    return(target);
}
