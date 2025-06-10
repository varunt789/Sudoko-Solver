# Sudoko-Solver
Algorithm Summary
Backtracking Algorithm:

Tries filling each empty cell with numbers 1 to n.

Recursively proceeds to next cell.

If no valid number can be placed, it backtracks (undoes the previous step).

⚙️ How the Code Works
Initialization:

Constructor accepts the size n (e.g., 9 for 9x9) and the board.

boxSize = sqrt(n) handles general n x n Sudoku (e.g., 4x4, 9x9, 16x16).

isSafe(row, col, num):

Checks if placing num at (row, col) violates:

Row constraint

Column constraint

Box constraint (uses boxSize to determine box boundaries)

solve():

Traverses the board to find the first empty cell.

Tries placing valid numbers (1 to n) in that cell.

Calls itself recursively to solve the next cells.

If a dead-end is hit, it backtracks.

solveAndPrint():

Triggers solving and prints the final board if successful.

Otherwise, prints "No solution exists!".
