#include "push_swap.h"

static t_node *remove_top(t_node **src)
{
    t_node *node;
    t_node *last;

    if(!src || !*src)
        return (NULL);
    
    node = *src;
    if(node->next == node)
        *src = NULL;
    else
    {
        last = node->prev;
        *src = node->next;
        last->next = (*src);
        (*src)->prev = last;
    }
    return (node);
}

static void add_top(t_node **dst, t_node *node)
{
    t_node *last;

    if(!node)
        return;

    if(!*dst)
    {
        node->next = node;
        node->prev = node;
        *dst = node;
    }
    else
    {
        last = (*dst)->prev;
        node->next = *dst;
        node->prev = last;
        (*dst)->prev = node;
        last->next = node;       
        *dst = node;
    }
}

void pa(t_node **a, t_node **b)
{
    t_node *node;

    node = remove_top(b);
    if(!node)
        return;
    add_top(a, node);
    write(1, "pa\n", 3);
}

void pb(t_node **a, t_node **b)
{
    t_node *node;

    node = remove_top(a);
    if(!node)
        return;
    add_top(b, node);
    write(1, "pb\n", 3);
}
