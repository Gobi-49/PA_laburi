#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
    return a>b ? a : b;
}
int rucsac(int *m, int *v, int r, int n) {
    int D[n + 1][r + 1];   
    for(int i = 0; i <= r; i++) {
        D[0][i] = 0;
        D[1][i] = v[0];
    }
    for(int i = 0; i <= n; i++) {
        D[i][0] = 0;
    } 
    for(int i = 2; i <= n; i++) {
        int k=i;
        for (int j = 1; j <= r; j++) {
            D[i][j] = max(v[i]+ D[i-1][j- k], D[i-1][j]);
        }
    }
 
    return D[n][r];
}

int main() {

    FILE *in = fopen("rucsac.in","r");
    int n;
    fscanf(in, "%d", &n);
    int v[n+1], m[n+1];
    for(int i = 0; i < n; i++) {
        fscanf(in, "%d", m+i);
    }
        for(int i = 0; i < n; i++) {
        fscanf(in, "%d", v+i);
    }
    int r;
    fscanf(in, "%d", &r);

    int val = rucsac(m, v, r, n);
    printf("valoarea in rucsac: %d\n", val);

    return 0;
}