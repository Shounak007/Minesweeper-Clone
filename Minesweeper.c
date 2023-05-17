// C Minesweeper Project
// Made by Shounak Mukherjee

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MINES 10

void initializeBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '-'; // Initialize all cells as unmarked
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    int i, j;
    printf("  ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i); // Print column numbers
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i); // Print row numbers
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]); // Print cell value
        }
        printf("\n");
    }
}

void placeMines(char board[SIZE][SIZE]) {
    int i, j, count = 0;
    while (count < MINES) {
        i = rand() % SIZE; // Generate random row index
        j = rand() % SIZE; // Generate random column index
        if (board[i][j] != '*') { // Check if the cell is already marked as a mine
            board[i][j] = '*'; // Mark the cell as a mine
            count++; // Increment the mine count
        }
    }
}

int countAdjacentMines(char board[SIZE][SIZE], int row, int col) {
    int count = 0;
    int i, j;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && board[i][j] == '*') {
                count++; // Increment the count if the adjacent cell is a mine
            }
        }
    }
    return count;
}

void revealCell(char board[SIZE][SIZE], char revealed[SIZE][SIZE], int row, int col) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && revealed[row][col] != 'R') {
        revealed[row][col] = 'R'; // Mark the cell as revealed
        if (board[row][col] == '0') {
            int i, j;
            for (i = row - 1; i <= row + 1; i++) {
                for (j = col - 1; j <= col + 1; j++) {
                    revealCell(board, revealed, i, j); // Recursive call to reveal adjacent cells
                }
            }
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    char revealed[SIZE][SIZE];
    int row, col, minesLeft = MINES, moves = 0;
    srand(time(NULL));

    initializeBoard(board); // Initialize the game board
    initializeBoard(revealed); // Initialize the revealed board
    placeMines(board); // Place the mines randomly on the board

    while (minesLeft > 0) {
        printf("Mines left: %d\n", minesLeft);
        printBoard(revealed); // Print the current state of the revealed board

        printf("Enter a row and column (0 to %d): ", SIZE - 1);
        scanf("%d %d", &row, &col); // Get the player's move

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && revealed[row][col] != 'R') {
            if (board[row][col] == '*') {
                printf("Game over! You hit a mine.\n");
                break;
            } else {
                int count = countAdjacentMines(board, row, col); // Count the adjacent mines
                revealed[row][col] = count + '0'; // Update the revealed board with the count
                minesLeft--;
                moves++;
                if (minesLeft == 0) {
                    printf("Congratulations! You won the game in %d moves.\n", moves);
                    break;
                }
                if (count == 0) {
                    revealCell(board, revealed, row, col); // Reveal the adjacent cells if count is zero
                }
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    if (minesLeft > 0) {
        printf("Game over! You lost.\n");
    }

    return 0;
}
