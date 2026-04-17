#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int board[MAX][MAX];
int moves = 0;
int N;

int isSafe(int row, int col)
{
    int i, j;

    for(i = 0; i < col; i++)
        if(board[row][i])
            return 0;

    for(i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
            return 0;

    for(i=row, j=col; j>=0 && i<N; i++, j--)
        if(board[i][j])
            return 0;

    return 1;
}

int solve(int col)
{
    if(col >= N)
        return 1;

    for(int i = 0; i < N; i++)
    {
        moves++;

        if(isSafe(i, col))
        {
            board[i][col] = 1;

            if(solve(col + 1))
                return 1;

            board[i][col] = 0;
        }
    }
    return 0;
}

void printBoard()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main()
{
    printf("Enter value of N: ");
    scanf("%d",&N);

    clock_t start = clock();

    if(solve(0) == 0)
    {
        printf("No solution exists\n");
        return 0;
    }

    clock_t end = clock();

    printBoard();

    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\nTotal moves tried: %d\n", moves);
    printf("Time consumed: %.6f seconds\n\n", time_taken);

    printf("Nitesh Kumar\n");
    printf("Regd No: 2401020478\n");

    return 0;
}