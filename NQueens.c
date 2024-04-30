#include <stdbool.h>
#include <stdio.h>
#define N 4

void printSolution(int board[N][N])
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for(i = 0; i < col; i++)
        if(board[row][i])
            return false;

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    for(i = row, j = col; j >= 0 && i < N; i++, j--)
        if(board[i][j])
            return false;
    return true;
}

bool NqueenUtil(int board[N][N], int col)
{
    int i;
    if(col >= N)
        return true;

    for(i = 0; i < N; i++)
    {
        if(isSafe(board, i, col))
        {
            board[i][col] = 1;
            if(NqueenUtil(board, col + 1)) // we are checking for rest of the rows for a queen placed in a particular column  col
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQ()
{
    int board[N][N] = { {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0} };

    if(!NqueenUtil(board, 0))
    {
        printf("Solution does not exist");
        return false;
    }
    
    printSolution(board);
    return true;
}

int main()
{
    solveNQ(); // Added parentheses to call the solveNQ function
    return 0;
}
