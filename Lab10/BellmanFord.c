#include <stdio.h>
#include <stdlib.h>
#define INF 1000000


void BellmanFord(int n, int m, int **cost, int s) {
    int d[n+1], p[n+1];
    for(int i = 1; i <= n; i++) {
        d[i] = -1;
        p[i] = -1;
    }
    d[s] = 0;
    for(int i = 1; i < n; i++) {
        printf("iteratia: %d\nrelaxari: ", i);
        for(int u = 1; u <= n; u++) {
            for(int v = 1; v <= n; v++) {
                if(cost[u][v] != 0) {
                    if((d[v] > d[u] + cost[u][v] && cost[u][v] != 0) || (d[v] == -1 && d[u] + cost[u][v] > 0)) {
                        d[v] = d[u] + cost[u][v];
                        p[v] = u;
                        printf("(%d, %d) ", u, v);
                        printf("\n");
                        for(int j=1;j<=n;j++) {
                        printf("%d ", j);
                        }
                        printf("\n");
                        for(int i=1;i<=n;i++) {
                            printf("%d ", d[i]);
                        }
                        printf("\n");
                        for(int i=1;i<=n;i++) {
                            printf("%d ", p[i]);
                        }
                        printf("\n---------------------------\n");
                    }
                }
            }
        }
    }
    for(int u = 1; u <= n; u++) {
        for(int v = 1; v <= n; v++) {
            if(cost[u][v] != 0) {
                if(d[v] > d[u] + cost[u][v] && cost[u][v] != 0) {
                    printf("Graf cu ciclu negativ\n");
                    return;
                }
            }
        }
    }
}

int main() {

    FILE *in = fopen("graf.in", "r");
    int n, m;
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);
    int **cost;
    cost = (int**)calloc(n+1, sizeof(int*));
    for(int i = 0; i < n+1; i++) {
        cost[i] = (int*)calloc(n+1, sizeof(int));
    }
    int x, y, z;
    for(int i = 0; i < m; i++) {
        fscanf(in, "%d", &x);
        fscanf(in, "%d", &y);
        fscanf(in, "%d", &z);
        cost[x][y] = z;
    }

    BellmanFord(n, m, cost, 1);
    return 0;
}