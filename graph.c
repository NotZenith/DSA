#include<stdio.h>
#define MAX 10
#define INF 99999

int minDistance(int dist[], int visited[], int n){
    int min = INF;
    int minIndex = -1;
    
    for(int i = 0; i< n; i++){
        if(visited[i] == 0 && dist[i] < min){
            min  = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int n, int source){
    int dist[MAX];
    int visited[MAX];

    for(int i = 0; i< n; i++){
        dist[i]= INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    for(int count = 0; count < n-1; count++){
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        
        for(int v = 0; v < n; v++){
            if(visited[v] == 0 &&
            graph[u][v] != 0 &&
            dist[u] != INF &&
            dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distance from vertex %d: \n", source);
    printf("Vertex\tDistance\n");

    for(int i = 0; i < n; i++){
        printf("%d\t%d\n",i, dist[i]);
    }
}

int main(){

    int graph[MAX][MAX];
    int n, source;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("\nEnter adjacency matrix: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter source vertex: ");
    scanf("%d", &source);
    
    dijkstra(graph, n, source);

    return 0;
}
