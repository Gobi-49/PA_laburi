#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1000000

int temp;
void DFS(int val, int *visited, int *d, int *f, int n, int **graph) {
    
    visited[val] = 1;
    temp++;
    d[val] = temp;

    for (int i = 1; i <= n; i++) {
        if(graph[val][i]!=0 && visited[i] == 0) {
           DFS(i, visited, d, f, n, graph);
        }
    }
    
    temp++;
    f[val] = temp;
}

void sortF(int f[], int topological[], int n) {
    int aux;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(f[i] < f[j]) {
                aux = f[i];
                f[i] = f[j];
                f[j] = aux;
                aux = topological[i];
                topological[i] = topological[j];
                topological[j] = aux;
            }
        }
    }
}

int main() {
    int n, m, s;
    FILE *in = fopen("date.in", "r");
    FILE *out = fopen("date.out", "w");
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);
    fscanf(in, "%d", &s);
    int **c = (int**)calloc(n+1, sizeof(int*));
    for(int i=1; i<=n; i++) {
        c[i] = (int*)calloc(n+1, sizeof(int));
    }


    int u, v;
    for(int i=0; i<m; i++) {
        fscanf(in, "%d", &u);
        fscanf(in, "%d", &v);
        fscanf(in, "%d", &c[u][v]);
    }

    int *viz= (int*)calloc((n+1),sizeof(int));
    int *d = (int*)calloc((n+1),sizeof(int));
    int *f = (int*)calloc((n+1),sizeof(int));


    DFS(s,viz,d,f,n,c);

    int *topological = (int*)malloc((n+1)*sizeof(int));

    for(int i=1; i<=n; i++) {
        topological[i] = i;
    }

    sortF(f, topological, n);

    int dist[n+1];
    for(int i=1; i<=n; i++) {
        dist[i] = INF;
    }

    dist[s] = 0;
    for(int i=1; i<=n;i++) {
        if(topological[i]!=0) {
            for(int j=1;j<=n;j++) {
                if(c[i][j]!=0) {
                    if(dist[j] > dist[i] + c[i][j]) {
                        dist[j] = dist[i] + c[i][j];
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(dist[i]==INF)
            fprintf(out, "%d ", -1);
        else
            fprintf(out, "%d ", dist[i]);
    }

    return 0;
}
