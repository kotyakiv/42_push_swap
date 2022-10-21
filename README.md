# 42_push_swap
The goal of this project is to sort all numbers in a stack with the samllest number of operations. This project consist of two programms **push_swap** and
**checker**. **push-swap** prints operations to sort algo and **checker** checks if operations really sorts the stack.
For this project students
need go through the bunch of sorting algorithm and choose the best suits for this task. I decided to implement and modify quicksort algortihm. 
## Rules
Two stacks **a** and **b**. **b** is empty in the start and in the end. The goal is to sort in ascending order numbers into stack a.
#### permitted operations
- **sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).  
- **sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).  
- **ss** : sa and sb at the same time.  
- **pa** : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.  
- **pb** : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.  
- **ra** : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.  
- **rb** : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.  
- **rr** : ra and rb at the same time.  
- **rra** : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one  
- **rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
- **rrr** : rra and rrb at the same time.
## push_swap
#### Input
Pass numbers as arguments. There couldn't be numbers bigger than integers and no duplicates, otherwise it's an error.
```
./push_swap 12 43 100000 -7 0 3 50
```
#### Output
```
ra
ra
ra
pb
pb
pb
ra
pb
pb
ra
pa
pa
pa
pa
pa
```
## checker
**checker**s output is only **OK** or **KO**. For checking push_swap:
```
 ./push_swap 12 43 100000 -7 0 3 50 | ./checker 12 43 100000 -7 0 3 50
 OK
```
Also it is possible to type commands manually:
```
./checker 12 43 100000 -7 0 3 50
ra
pa
pb
KO
```
## Visualizer
- **install**
```
pip3 install push_swap_gui
```
- **run**
```
python3 -m push_swap_gui
```
more inforamtion on https://pypi.org/project/push-swap-gui/
