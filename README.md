# Push swap

# How I stock my number?

I create an int array of the number of arguments.
My two stack are just pointer of a place in the array.
A stack is a stuct with a pointer and a lenght.
I thinks it's an esier idea than the others dude...

```
int	num[5] = {12, 5, 6, 1, 0};

init:
A -> pointer = num[0]
A -> lenght = 5
[0] [1] [2] [3] [4]
 A--------------->

push(A, B):
[0] [1] [2] [3] [4]
 B   A----------->

push(A, B):
[0] [1] [2] [3] [4]
 B--->   A------->
```
