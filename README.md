### SuperKnight
------
A rectangular board is divided into M rows and N columns *(2 <= M, N <= 100)*. A SuperKnight jumps from one square **x** to another square **y** as follows: from **x**, it moves **p** squares, either horizontally or vertically, and then it moves **q** squares in a direction perpendicular to the previous to get to **y**. It can move horizontally either to the left or to the right and vertically either up or down. *(A SuperKnight move is similar to a knight move in chess with p = 2 and q = 1)*.

Assume that the **top-left square is (1, 1)** and the **bottom-right square is (M, N)**. The SuperKnight is put in the square with coordinates (X, Y) *(1 <= X <= M, 1 <= Y <= N)*. The SuperKnight wishes to get to a different square (U, V) (1 <= U <= M, 1 <= V <= N) using only the jumps described above. It is required to find the **minimal number, S**, of jumps needed to get to (U, V) and the
sequence of squares visited in reaching (U, V). If there is more than one sequence, you need find only one.
If it is not possible to get to (U, V) from (X, Y), print an appropriate message.
For example, consider a board with 7 rows and 4 columns, with p = 2, q = 1. Suppose the SuperKnight
starts in square (3, 1) and it needs to get to square (6, 1). It can do so in 3 moves by jumping to (5, 2)
then (7, 3) then (6, 1).
Write a program which reads values for M, N, p, q, X, Y, U, V in that order and prints the minimum number
of moves followed by the squares visited or a message that the SuperKnight cannot get to the destination
square from the starting one.

##### Sample input
`7 4 2 1 3 1 6 1`
##### Sample output

`3`

`(3, 1)`

`(5, 2)`

`(7, 3)`

`(6, 1)`

