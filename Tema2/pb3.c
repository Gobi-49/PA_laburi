#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void Dijkstra(int n, int m, int **cost, int s, int *d) {
    for(int i = 1; i <= n; i++) {
        d[i] = -1;
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
        if(u==0) 
            break;
        for(int v = 1; v <= n; v++) {
            if((d[v] > d[u] + cost[u][v] && cost[u][v] != 0) || (d[v] == -1 && d[u] + cost[u][v] > 0 && cost[u][v] != 0)) {
                d[v] = d[u] + cost[u][v];
            }
        }
        used[u] = 1;
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

    int *d = (int*)calloc((n+1),sizeof(int));

    Dijkstra(n, m, c, s, d);

    for(int i=1; i<=n; i++) {
        fprintf(out, "%d ", d[i]);
    }

    return 0;
}
