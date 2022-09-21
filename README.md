# Push swap

# How I stock my number?

I create an int array of the number of arguments.
My two stack are just pointer of a place in the array.
A stack is a stuct with a pointer and a lenght.
I thinks it's an esier idea than the others dude...

```
int	num[5] = {2, 5, 6, 1, 0};

init:
A -> pointer = num[0]
A -> lenght = 5
{2,  5,  6,  1,  0}
[0] [1] [2] [3] [4]
 A--------------->
 2
 5
 6
 1
 0
 A               B

push(A, B):
{2,  5,  6,  1,  0}
[0] [1] [2] [3] [4]
 B   A----------->
 5
 6
 1
 0               2
 A               B
 
push(A, B):
{2,  5,  6,  1,  0}
[0] [1] [2] [3] [4]
 <---B   A------->
 6
 1              5
 0              2
 A              B
 
{2,  5,  6,  1,  0}
[0] [1] [2] [3] [4]
 <---------------B

push(B, A):
{2,  5,  6,  1,  0}
[0] [1] [2] [3] [4]
 <-----------B   A

swap(B):
swap number in [2] and [3]
{2,  5,  1,  6,  0}
[0] [1] [2] [3] [4]
 <-----------B   A
```
