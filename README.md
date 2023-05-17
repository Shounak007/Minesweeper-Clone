# Minesweeper-Clone
# Created By Shounak Mukherjee

This program is an implementation of the classic game Minesweeper using the C programming language. It provides a text-based interface where players can uncover cells on a grid, while avoiding hidden mines.

Key Concepts Utilized
# Arrays: 
The program uses a two-dimensional array to represent the game board. The array stores information about the presence of mines and the number of adjacent mines for each cell.
# Randomization:
The rand() function from the C standard library is used to randomly place mines on the game board. This adds an element of unpredictability to each game session.
# Recursion:
Recursive functions are employed to reveal cells on the board. When a cell with no adjacent mines is uncovered, the program recursively uncovers neighboring cells until cells with adjacent mines are encountered.
# Conditional Statements:
The code utilizes conditional statements (if and if-else) to handle various game scenarios, such as checking if a cell is valid, determining if a mine is present, or deciding when to end the game.
# Boolean Logic:
The program uses boolean variables and operators (true, false, &&, ||) to track the state of cells (revealed or hidden) and to control game flow based on different conditions.
# Functions:
The program is divided into several functions, each responsible for a specific task such as initializing the game board, placing mines, counting adjacent mines, revealing cells, and printing the game board.
These key concepts are essential for understanding and implementing the Minesweeper game logic in C. By leveraging these concepts, the program creates an interactive gaming experience for the player.

# How does this work?

The necessary header files stdio.h, stdlib.h, and time.h are included to provide the required functions for input/output, memory allocation, and time-related operations.
The constants SIZE and MINES are defined to set the dimensions of the game board (10x10) and the number of mines (10).
The function initializeBoard takes a 2D array board as a parameter and initializes all cells of the board with the character '-', representing an unmarked cell.
The function printBoard is responsible for displaying the current state of the game board. It iterates over the rows and columns of the board array and prints the corresponding cell values.
The function placeMines randomly distributes the mines on the game board. It uses a loop to generate random row and column indices and marks those cells with a mine ('*'). The loop continues until the desired number of mines (MINES) is placed.
The function countAdjacentMines takes the board array, along with the current row and column indices, as input. It counts the number of adjacent cells that contain mines. It checks the cells in a 3x3 grid centered around the specified row and column and increments the count whenever a mine ('*') is encountered.
The function revealCell is a recursive function that uncovers cells on the board. It takes the board array, the revealed array, and the current row and column indices as input. If the specified cell is within the bounds of the board and has not already been revealed, it marks the cell as revealed ('R'). If the cell contains a '0', indicating no adjacent mines, it recursively calls revealCell for each adjacent cell.
In the main function, the board and revealed arrays are declared to represent the game board and the revealed state of the board, respectively. The variables row, col, minesLeft, and moves are used to track the player's moves, remaining mines, and the number of moves taken.
The srand function is called with the current time as the seed to initialize the random number generator.
The initializeBoard function is called twice to initialize the board and revealed arrays.
The placeMines function is called to randomly distribute the mines on the game board.
The main game loop starts with a while loop that continues until all the mines are uncovered or a mine is hit.
Inside the loop, the current state of the game is displayed using the printBoard function.
The player is prompted to enter a row and column index to uncover a cell.
The validity of the input is checked to ensure it is within the bounds of the board and has not been previously revealed.
If the selected cell contains a mine ('*'), the game is over, and the loop is exited.
Otherwise, the countAdjacentMines function is called to determine the number of adjacent mines. The revealed board is updated with this count, and the number of remaining mines and moves are adjusted accordingly.
If there are no adjacent mines (count == 0), the revealCell function is called to uncover adjacent cells recursively.
After each move, the game checks if the player has uncovered all non-mine cells. If so, the player wins the game.
If the game loop ends without the player winning, it means the player hit a mine, and the game is lost.
The appropriate end-of-game messages are displayed, and the program exits with a return value of 0.
