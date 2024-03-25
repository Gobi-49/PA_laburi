#include <stdio.h>
#include <string.h>

int sume(int k, int n) {
    int d[n*n];
    char sol[n+1][n*n][n+1];
    d[0] = 1; d[1] = 1;
    strcpy(sol[1][1], "v");
    strcpy(sol[0][1], "\0");
    for(int i = 2; i <= n; i++) {
        if(i-k >= 0){
            d[i] = d[i-1] + d[i - k];
            for(int j = 1; j <= d[i-1]; j++) {
                strcpy(sol[i][j], sol[i-1][j]);
                strcat(sol[i][j], "v");
            }
            for(int j = 1; j <= d[i-k]; j++) {
                strcpy(sol[i][j+d[i-1]], sol[i-k][j]);
                strcat(sol[i][j+d[i-1]], "o");
            }
        } else {
            d[i] = d[i-1];
            for(int j = 1; j <= d[i-1]; j++) {
                strcpy(sol[i][j], sol[i-1][j]);
                strcat(sol[i][j], "v");
            }
        }
    }

    for(int i = 1; i <= d[n]; i++)
        printf("%s \n", sol[n][i]);
    return d[n];
}

int main() {
    FILE *in = fopen("garduri.in", "r");
    int k, n;
    fscanf(in, "%d", &k);
    fscanf(in, "%d", &n);
    printf("%d \n", sume(k, n));
    return 0;
}