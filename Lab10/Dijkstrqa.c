#include <stdio.h>
#include <stdlib.h>
#define INF 1000000

int empty(int *used, int n) {
    for(int i=1; i <= n; i++)
        if(used[i]!=1)
            return 0;
    return 1;
}

int extract(int *d, int *used, int n) {
    int min = INF, pos = 0;
    for(int i = 1; i <= n; i++) {
        if(d[i] != -1) {
            if(d[i] < min && used[i] == 0) {
                min = d[i];
                pos = i;
            }
        }
    }
    return pos;
}

void Dijkstra(int n, int m, int **cost, int s) {
    int d[n+1], p[n+1];
    for(int i = 1; i <= n; i++) {
        d[i] = -1;
        p[i] = -1;
    }
    int q[n+1];
    int used[n+1];
    for(int i = 1; i <= n; i++) {
        q[i] = i;
        used[i] = 0;
    }
    d[s] = 0;
    while (!empty(used,n)) {
        int u = extract(d,used,n);
        for(int v = 1; v <= n; v++) {
            if((d[v] > d[u] + cost[u][v] && cost[u][v] != 0) || (d[v] == -1 && d[u] + cost[u][v] > 0)) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
            }
        }
        used[u] = 1;
        printf("selected: %d\n", u);
        for(int i=1;i<=n;i++) {
            printf("%d ", q[i]);
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

int main() {

    FILE *in = fopen("graf.in", "r");
    int n, m;
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);
    int **cost;
    cost = (int**)calloc(n+1, sizeof(int*));
    for(int i = 0; i < n+1; i++) {
        cost[i] = (int*)calloc(m+1, sizeof(int));
    }
    int x, y, z;
    for(int i = 0; i < m; i++) {
        fscanf(in, "%d", &x);
        fscanf(in, "%d", &y);
        fscanf(in, "%d", &z);
        cost[x][y] = z;
    }

    Dijkstra(n, m, cost, 1);
    return 0;
}