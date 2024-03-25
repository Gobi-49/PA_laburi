#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp;
int DFS(int val, int *visited, int *d, int *f, int n, int **graph) {
    
    visited[val] = 1;
    temp++;
    d[val] = temp;
    
    int ok = 1;

    for (int i = 1; i <= n && ok!=0; i++) {
        if(graph[val][i]!=0) {
            if (visited[i] == 0) { 
                ok = DFS(i, visited, d, f, n, graph);
            } else {
                if(f[i] == 0)
                    return 0;
            }
        }
    }
    
    temp++;
    f[val] = temp;
    return ok;
}

int main() {
    int n, m;
    FILE *in = fopen("date.in", "r");
    FILE *out = fopen("date.out", "w");
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);
    int **g = (int**)calloc(n+1, sizeof(int*));
    for(int i=1; i<=n; i++) {
        g[i] = (int*)calloc(n+1, sizeof(int));
    }


    int u, v;
    for(int i=0; i<m; i++) {
        fscanf(in, "%d", &u);
        fscanf(in, "%d", &v);
        g[u][v] = 1;
    }

    int viz[n+1];
    int d[n+1];
    int f[n+1];

    for(int i=1; i<=n; i++) {
        viz[i] = 0;
        d[i] = 0;
        f[i] = 0;
    }

    int ok=1;

    for(int i=1; i<=n && ok==1; i++) {
        if(viz[i]==0){
            ok = DFS(i,viz,d,f,n,g);
        }
    }
    
    if(ok==0)
        fprintf(out, "1");
    else
        fprintf(out, "0");

    return 0;
}
