*This project has been created as part of the 42 curriculum by krabans*

# Push_swap

## Description

**Push_swap** is a sorting algorithm project. It's goal is to sort a stack of integers using a limited set of operations and a second auxiliary stack, while minimizing the total number of moves. The program takes a list of integers as arguments, and outputs the sequence of operations needed to sort them in ascending order.

### How it works

Two stacks are used:
- **Stack A** — initially contains all the integers in the given order
- **Stack B** — starts empty and is used as auxiliary storage

The allowed operations are:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap top 2 elements of stack A |
| `sb` | Swap top 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B onto A |
| `pb` | Push top of A onto B |
| `ra` | Rotate A upward (top goes to bottom) |
| `rb` | Rotate B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (bottom goes to top) |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` and `rrb` simultaneously |

### Algorithm

This implementation uses the **Turk Algorithm** — a greedy cost-based approach:

1. Push all elements except 3 from stack A to stack B
2. Sort the remaining 3 elements in stack A using hardcoded moves
3. For each element in stack B, calculate the cost to insert it into the correct position in stack A
4. Push the cheapest element back to stack A
5. Repeat until stack B is empty
6. Rotate stack A so the minimum element is on top

### Performance

| Input size | Max moves (full score) | Achieved |
|------------|----------------------|----------|
| 3 numbers  | 3 moves              | ✅ |
| 5 numbers  | 12 moves             | ✅ |
| 100 numbers | 700 moves           | ~559 ✅ |
| 500 numbers | 5500 moves          | ~4985 ✅ |

---
## Instructions

### Requirements

- GCC compiler
- GNU Make
- libft library (included in `libft/` directory)

### Compilation

```bash
# clone the repository
git clone <repository_url>
cd push_swap

# compile
make

# clean object files
make clean

# remove all compiled files
make fclean

# recompile from scratch
make re
```

### Execution

```bash
# basic usage
./push_swap 3 1 4 2 5

# with quoted arguments
./push_swap "3 1 4 2 5"

# with negative numbers
./push_swap -3 1 -4 2 5

# count number of moves
./push_swap 3 1 4 2 5 | wc -l

# verify correctness with checker
./push_swap 3 1 4 2 5 | ./checker_linux 3 1 4 2 5
```

### Error handling

The program writes `Error` to stderr and exits in the following cases:
- Non-integer arguments
- Duplicate integers
- Integer overflow (outside INT_MIN to INT_MAX range)
- Arguments with only a sign character (`+` or `-`)

```bash
./push_swap 1 2 a      # Error
./push_swap 1 2 1      # Error (duplicate)
./push_swap 2147483648 # Error (overflow)
./push_swap +          # Error
```

---
## Resources

https://www.youtube.com/watch?v=R9PTBwOzceo - to understand linked list

//ai to understand about self referencing struct.

https://www.geeksforgeeks.org/dsa/insertion-in-doubly-circular-linked-list/ - to understand creating the node and about double curcular linked list

https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0 - to understand turk algorithm

### AI usage
- Chatgpt was used to understand about self referencing struct.
- Claude was used to for the overall roadmap, learning and debugging the project. Understanding turk algorithm steps, cost calculate logic andn circular  doubly linked list behaviour. Identifyiing the bugs such as wrong pointer dereferncing and incorrect overflow checks.




