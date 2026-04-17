#include <stdio.h>
#include <stdlib.h>

#define V 15
#define E 18

struct Edge {
    int src, dest, weight;
};

struct subset {
    int parent;
};

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    subsets[find(subsets, y)].parent = find(subsets, x);
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void KruskalMST(struct Edge edges[]) {
    struct subset subsets[V];
    int e = 0, i = 0, passes = 0;

    qsort(edges, E, sizeof(edges[0]), compare);

    for (int v = 0; v < V; v++)
        subsets[v].parent = v;

    printf("\nEdges in MST (Kruskal's):\n");

    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);
        passes++;

        if (x != y) {
            printf("%d - %d weight = %d\n", next.src, next.dest, next.weight);
            Union(subsets, x, y);
            e++;
        }
    }

    printf("Number of components: 1\n");
    printf("Number of passes: %d\n", passes);
}

int main() {
    struct Edge edges[E] = {
        {0,1,8},{1,2,2},{1,3,3},{3,4,4},
        {2,5,3},{3,5,4},{5,7,2},{5,14,3},
        {14,6,2},{7,6,7},{7,9,8},{9,10,5},
        {10,12,5},{12,13,2},{9,12,10},
        {3,11,10},{11,10,10},{14,8,8}
    };

    KruskalMST(edges);

     printf ("Jyot Rathore\n") ;
    printf ("2401020465") ;

    return 0;
}
