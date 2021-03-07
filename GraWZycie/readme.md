# The Game of Life  
The Game of Life is one of the first and most famous examples of a cellular slot machine. It was invented in 1970 by the British mathematician John Conway.

The game is played on a rectangular board, divided into square cells with a side length of one. Each cell has eight neighbors - adjacent on the sides and touching vertices, except for the edges of the board, where there are fewer of these neighbors. <br/>
Every cell is alive or dead. Each turn of the game, first all cells (both alive and dead) count the number of their living neighbors. Then, at the same time, all cells change their state according to the following rules:
* a cell with exactly three living neighbors becomes alive, regardless of its previous state,
* a cell with exactly two living neighbors does not change (alive remains alive, dead remains dead),
* in other cases, the cell dies. <br/>
We will call a group of living cells a cluster of living cells in which each living cell is either adjacent to another living cell of the group or is adjacent to a dead cell which in turn is adjacent to a living cell of the group. In the example below, the dots represent dead cells and the letters describe living cells by grouping:
```
A.A.A....D
..........
A.A.A.....
..........
.......C.C
BBB......C
BBB...CCCC
```

The task is to calculate the K-th game turn (the starting board is a zero turn) and find the largest group of living cells on it.

## Entrance
The input will indicate the width (x) height (y) of the board and the number of turns K. No dimension will be smaller than 3 and greater than 100, and the number of turns will be between 0 and 10,000. In the following y lines, a description will appear the starting board. Each line will contain x characters. (period) or # (hash). The dot means a dead cell, the # sign means a living cell.
## Exit
The output should contain one number - the number of living cells in the largest group in the K-th game turn.


### Example
#### Entrance
```
7 7 21
.#.....
..#....
###....
.......
.......
.......
.......
```

#### Exit
4
