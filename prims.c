#include <stdio.h>
#define V 15
#define INF 9999

int minKey(int key[], int mstSet[]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];
    int passes = 0;

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        passes++;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printf("\nEdges in MST (Prim's):\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d  weight = %d\n", parent[i], i, graph[i][parent[i]]);

    printf("Number of components: 1\n");
    printf("Number of passes: %d\n", passes);
}

int main() {
    int graph[V][V] = {0};

    
    graph[0][1]=8;  graph[1][0]=8;
    graph[1][2]=2;  graph[2][1]=2;
    graph[1][3]=3;  graph[3][1]=3;
    graph[3][4]=4;  graph[4][3]=4;
    graph[2][5]=3;  graph[5][2]=3;
    graph[3][5]=4;  graph[5][3]=4;
    graph[5][7]=2;  graph[7][5]=2;
    graph[5][14]=3; graph[14][5]=3;
    graph[14][6]=2; graph[6][14]=2;
    graph[7][6]=7;  graph[6][7]=7;
    graph[7][9]=8;  graph[9][7]=8;
    graph[9][10]=5; graph[10][9]=5;
    graph[10][12]=5;graph[12][10]=5;
    graph[12][13]=2;graph[13][12]=2;
    graph[9][12]=10;graph[12][9]=10;
    graph[3][11]=10;graph[11][3]=10;
    graph[11][10]=10;graph[10][11]=10;
    graph[14][8]=8; graph[8][14]=8;

    primMST(graph);

    printf ("Jyot Rathore\n") ;
    printf ("2401020465") ;
    

    return 0;
}
