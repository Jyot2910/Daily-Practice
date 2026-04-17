#include <stdio.h>
#include <limits.h>

#define V 15
#define E 11

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int src)
{
    int dist[V];
    int i, j;

    for(i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for(i = 1; i <= V - 1; i++)
    {
        for(j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for(i = 0; i < V; i++)
    {
        if(dist[i] == INT_MAX)
            printf("Distance from %d to %d = INF\n", src, i);
        else
            printf("Distance from %d to %d = %d\n", src, i, dist[i]);
    }
}

int main()
{
    struct Edge edges[E] = {
        {0,1,8},
        {1,2,2},
        {1,3,3},
        {1,4,6},
        {2,5,3},
        {3,4,4},
        {3,11,10},
        {5,7,2},
        {7,14,2},
        {14,8,8},
        {14,6,2}
    };

    int src;

    printf("Enter source vertex (0-14): ");
    scanf("%d", &src);

    bellmanFord(edges, src);

    printf(" Ishika Kumari\n");
    printf("2401020464\n");

    return 0;
}
