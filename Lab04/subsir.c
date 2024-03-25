#include<stdio.h>
#include<stdlib.h>

void afisare(int *v, int *pre, int pas) {
    if(pre[pas] != -1)
        afisare(v, pre, pre[pas]);
    printf("%d ", v[pas]);
}

int subsir(int *v, int n) {
    int d[n], pre[n];
    pre[0] = -1;
    d[0] = 1;
    int iMax = 0, max = 0;
    for(int i = 1; i < n; i++) {
        int ok=0;
        for(int j = i-1; j >= 0; j--) {
            if(v[i] > v[j]) {
                d[i] = d[j] + 1;
                pre[i] = j;
                ok=1;
                break;
            }
        }
        if(ok=0) {
            pre[i] = -1;
            d[i] = 1;
        }
    }
    for(int i=0;i<n;i++) {
        if(d[i] > max) {
            max = d[i];
            iMax = i;
        }
    }
    afisare(v,pre,iMax);
    // for(int i=0;i<n;i++) {
    //     printf("%d ", d[i]);
    // }
    // printf("\n");
    // for(int i=0;i<n;i++) {
    //     printf("%d ", pre[i]);
    // }
    // printf("\n");
    return d[n-1];
}

int main() {

    FILE *in = fopen("subsir.in","r");
    int n;
    fscanf(in, "%d", &n);
    int v[n+1];
    for(int i = 0; i < n; i++) {
        fscanf(in, "%d", v+i);
    }

    int val = subsir(v,n);
    printf("lungime: %d\n", val);

    return 0;
}