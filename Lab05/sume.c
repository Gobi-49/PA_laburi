#include <stdio.h>
#include <stdlib.h>
int sumek(int v[], int n) {
    int **d = (int**)calloc(n+1, sizeof(int*));
    for(int i = 0; i <= n; i++)
        d[i] = calloc(3, sizeof(int));
    for(int i = 1; i <= n; i++) {
        if(v[i-1]%3 == 0) {
            d[i][0] = 1 + 2*d[i-1][0];
            d[i][1] = 2*d[i-1][1];
            d[i][2] = 2*d[i-1][2];
        }
        if(v[i-1]%3 == 1) {
            d[i][0] = d[i-1][0] + d[i-1][2];
            d[i][1] = 1 + d[i-1][0] + d[i-1][1];
            d[i][2] = d[i-1][2] + d[i-1][1];
        }
        if(v[i-1]%3 == 2) {
            d[i][0] = d[i-1][0] + d[i-1][1];
            d[i][1] = d[i-1][2] + d[i-1][1];
            d[i][2] = 1 + d[i-1][2] + d[i-1][0];
        }
    }

    for(int i = 1; i<= n; i++) {
        for(int j = 0; j <3 ; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }
    return d[n][0];
}

int main() {

    FILE *in = fopen("sume.in","r");
    int n;
    fscanf(in, "%d", &n);
    int v[n+1];
    for(int i = 0; i < n; i++) {
        fscanf(in, "%d", v+i);
    }
    int k;
    int val = sumek(v,n);
    printf("sume: %d\n", val);

    return 0;
}