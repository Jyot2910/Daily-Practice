#include <stdio.h>
#include <limits.h>

#define N 4

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int final_path[N + 1];
int visited[N];
int final_res = INT_MAX;

/* Utility functions */
int min(int a, int b) {
    return (a < b) ? a : b;
}

int firstMin(int i) {
    int min_val = INT_MAX;
    for (int k = 0; k < N; k++)
        if (graph[i][k] != 0 && i != k && graph[i][k] < min_val)
            min_val = graph[i][k];
    return min_val;
}

int secondMin(int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i == j || graph[i][j] == 0)
            continue;

        if (graph[i][j] <= first) {
            second = first;
            first = graph[i][j];
        } else if (graph[i][j] < second && graph[i][j] != first) {
            second = graph[i][j];
        }
    }
    return second;
}

/* Branch and Bound Recursion */
void TSPRec(int curr_bound, int curr_weight, int level, int curr_path[]) {
    if (level == N) {
        if (graph[curr_path[level - 1]][curr_path[0]] != 0) {
            int curr_res = curr_weight + graph[curr_path[level - 1]][curr_path[0]];

            if (curr_res < final_res) {
                for (int i = 0; i < N; i++)
                    final_path[i] = curr_path[i];
                final_path[N] = curr_path[0];
                final_res = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (graph[curr_path[level - 1]][i] != 0 && !visited[i]) {
            int temp = curr_bound;
            curr_weight += graph[curr_path[level - 1]][i];

            if (level == 1)
                curr_bound -= (firstMin(curr_path[level - 1]) + firstMin(i)) / 2;
            else
                curr_bound -= (secondMin(curr_path[level - 1]) + firstMin(i)) / 2;

            if (curr_bound + curr_weight < final_res) {
                curr_path[level] = i;
                visited[i] = 1;

                TSPRec(curr_bound, curr_weight, level + 1, curr_path);
            }

            curr_weight -= graph[curr_path[level - 1]][i];
            curr_bound = temp;

            for (int j = 0; j < N; j++)
                visited[j] = 0;
            for (int j = 0; j < level; j++)
                visited[curr_path[j]] = 1;
        }
    }
}

/* Branch and Bound Main */
void TSP() {
    int curr_path[N + 1];
    int curr_bound = 0;

    for (int i = 0; i < N; i++)
        curr_bound += (firstMin(i) + secondMin(i));

    curr_bound = (curr_bound % 2) ? curr_bound / 2 + 1 : curr_bound / 2;

    for (int i = 0; i < N; i++)
        visited[i] = 0;

    visited[0] = 1;
    curr_path[0] = 0;

    TSPRec(curr_bound, 0, 1, curr_path);

    printf("Optimal Cost (Branch & Bound): %d\n", final_res);
    printf("Path: ");
    for (int i = 0; i <= N; i++)
        printf("%d ", final_path[i]);
    printf("\n");
}

/* Nearest Neighbor Approximation */
void nearestNeighbor() {
    int visited[N] = {0};
    int path[N + 1];
    int cost = 0;

    int current = 0;
    path[0] = current;
    visited[current] = 1;

    for (int i = 1; i < N; i++) {
        int next = -1;
        int min_dist = INT_MAX;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && graph[current][j] != 0 && graph[current][j] < min_dist) {
                min_dist = graph[current][j];
                next = j;
            }
        }

        path[i] = next;
        visited[next] = 1;
        cost += min_dist;
        current = next;
    }

    cost += graph[current][0];
    path[N] = 0;

    printf("Approx Cost (Nearest Neighbor): %d\n", cost);
    printf("Path: ");
    for (int i = 0; i <= N; i++)
        printf("%d ", path[i]);
    printf("\n");
}

/* MAIN FUNCTION (IMPORTANT FIX) */
int main() {
    TSP();
    nearestNeighbor();
    printf("Simran Jaiswal\n");
    printf("Regd No - 2401020495 \n");
    return 0;
}