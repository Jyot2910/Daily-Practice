#include <stdio.h>
#define INF 999

int n, cost[10][10], visited[10];

int mincost(int city)
{
    int i, nextcity;
    int min = INF, temp;

    visited[city] = 1;
    printf("%d -> ", city + 1);

    for(i = 0; i < n; i++)
    {
        if(cost[city][i] != 0 && visited[i] == 0)
        {
            if(cost[city][i] < min)
            {
                min = cost[city][i];
                nextcity = i;
            }
        }
    }

    if(min != INF)
        return min + mincost(nextcity);

    return cost[city][0];
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Path: ");
    int total = mincost(0);

    printf("1\n");
    printf("Minimum cost = %d\n", total);

    return 0;
}