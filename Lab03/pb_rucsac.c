#include<stdio.h>
#include<stdlib.h>

void sort(int *rap, int *v, int *m, int n) {
    int aux;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(rap[i] < rap[j]) {
                aux = rap[i];
                rap[i] = rap[j];
                rap[j] = aux;
                aux = m[i];
                m[i] = m[j];
                m[j] = aux;
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int rucsac(int *m, int *v, int n, int R) {
    int val = 0;
    int rap[n+1];
    for(int i = 0; i < n; i++) {
        rap[i] = v[i]/m[i];
    }
    sort(rap, v, m, n);
    int i = 0;
    while (R > 0 && i < n) {
        if(m[i] > R){
            break;
        }
        else {
            val += v[i];
            R -= m[i];
            printf("val: %d, masa: %d\n", v[i], m[i]);
        }
        i++;
    }
    if(i < n && R > 0) {
        val += R*v[i]/m[i];
        printf("%f din val: %d, masa: %d\n",(double)R/m[i], v[i], m[i]);
    }
    
    return val;
}

int main() {

    FILE *in = fopen("rucsac.in","r");
    int n;
    fscanf(in, "%d", &n);
    int v[n+1], m[n+1];
    for(int i = 0; i < n; i++) {
        fscanf(in, "%d", m+i);
        fscanf(in, "%d", v+i);
    }
    int r;
    fscanf(in, "%d", &r);

    int val = rucsac(m, v, n, r);
    printf("valoarea in rucsac: %d\n", val);

    return 0;
}