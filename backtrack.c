#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[20], N;
long long moves;
int solutions;

int safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        moves++;
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solve(int row) {
    if (row == N) {
        solutions++;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (safe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    int test[] = {3, 4, 6, 8};

    for (int i = 0; i < 4; i++) {
        N = test[i];
        moves = 0;
        solutions = 0;

        clock_t start = clock();
        solve(0);
        clock_t end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nN = %d\n", N);
        printf("Solutions = %d\n", solutions);
        printf("Moves = %lld\n", moves);
        printf("Time = %f seconds\n", time);
    }

    return 0;
}