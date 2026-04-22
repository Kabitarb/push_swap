#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
    int data;
    int pos;
    int cost;
    int med;
    int targetpos;
    struct s_node *target;
    struct s_node *prev;
    struct s_node *next;
} t_node;


int parse(char **argv, t_node **s);
t_node *create_node(int number);
void append_node(t_node **head, int number);
void free_stack(t_node **head);
int error(void);
int validate(char **str);
int check_duplicate(t_node *head, int number);
void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);
void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);
void sa(t_node **a);
void sb(t_node **b);
void ss(t_node **a, t_node **b);
void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);
void three_sort(t_node **head);
int count(t_node *a);
void pushto_b(t_node **a, t_node **b);

#endif