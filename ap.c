#include <stdio.h>
#include <limits.h>

#define V 15
#define E 21
#define INF 99999

struct Edge{ int u,v,w; };

int main()
{
    struct Edge edges[E]={
    {0,1,8},{1,0,8},{1,2,2},{2,1,2},{1,3,3},{3,1,3},
    {1,4,6},{4,1,6},{3,4,4},{4,3,4},{2,5,3},{5,2,3},
    {3,11,10},{11,3,10},{5,7,2},{7,5,2},{7,14,2},
    {14,7,2},{14,8,8},{8,14,8},{6,14,2}
    };

    int dist[V][V];

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;

    for(int i=0;i<E;i++)
        dist[edges[i].u][edges[i].v]=edges[i].w;

    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            if(dist[i][j]==INF) printf("INF ");
            else printf("%3d ",dist[i][j]);
        printf("\n");
    }

    printf("Ishika Kumari\n");
    printf("2401020464\n");

    return 0;
}
