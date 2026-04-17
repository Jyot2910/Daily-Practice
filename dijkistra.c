#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100


struct Node {
    int vertex;
    int weight;
    struct Node* next;
};


struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}


void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int V, E;
    struct Node* adj[MAX] = {NULL};
    int dist[MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);   
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

   
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

  
    for (int count = 0; count < V - 1; count++) {

        
        int min = INT_MAX, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }

            temp = temp->next;
        }
    }

    printf("\nVertex\tDistance from %d\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}
