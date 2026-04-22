#include "push_swap.h"

void three_sort(t_node **head)
{
    if((*head)->data < (*head)->next->data && (*head)->next->data < (*head)->prev->data && (*head)->data < (*head)->prev->data)
        return;
    else if((*head)->data > (*head)->next->data && (*head)->next->data < (*head)->prev->data && (*head)->data < (*head)->prev->data)
        sa(head);
    else if((*head)->data < (*head)->next->data && (*head)->next->data > (*head)->prev->data && (*head)->data > (*head)->prev->data)
        rra(head);
    else if((*head)->data > (*head)->next->data && (*head)->next->data < (*head)->prev->data && (*head)->data > (*head)->prev->data)
        ra(head);
    else if((*head)->data > (*head)->next->data && (*head)->next->data > (*head)->prev->data && (*head)->data > (*head)->prev->data)
    {
        sa(head);
        rra(head);
    }
    else if((*head)->data < (*head)->next->data && (*head)->next->data > (*head)->prev->data && (*head)->data < (*head)->prev->data)
    {
        sa(head);
        ra(head);
    }
}