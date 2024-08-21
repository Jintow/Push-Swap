# Push_Swap

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, we will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

## Rules
* The game is composed of 2 stacks named a and b. <br>
* To start with: <br>
◦ a contains a random number of either positive or negative numbers without
any duplicates. <br>
◦ b is empty <br>
* The goal is to sort in ascending order numbers into stack a. <br>
* To do this we have the following operations at our disposal: <br>

| Command       | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| <b>sa</b>     | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). |
| <b>sb</b>     | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). |
| <b>ss</b>     | sa and sb at the same time. |
| <b>pa</b>     | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| <b>pb</b>     | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| <b>ra</b>     | rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| <b>rb</b>     | rotate b - shift up all elements of stack b by 1. The first element becomes the last one. |
| <b>rr</b>     | ra and rb at the same time. |
| <b>rra</b>    | reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one. |
| <b>rrb</b>    | reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one. |
| <b>rrr</b>    | rra and rrb at the same time. |
