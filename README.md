# SudokuSolver
This is a fun project to learn  C++ by writing a basic Sudoku Solving Algorithm using backtracking

The method of solving the Sudoku is by using Backtracking in which for each cell in the grid you try every number and check if it violates the 3 conditions of
the sudoku game. If all numbers have been attempted, the code will reset the cell and move back to the previous cell and will continue attempting until it solves
the grid. The method I made doesn't use recursion

The code is made to solve 9X9 Grids but can be modified to solve any vaild grid size such as 16X16.

The runtime to solve 50 different grids (See Grids.txt) is about 200ms. (On my system)
