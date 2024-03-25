#include<stdio.h>
#include<stdlib.h>

void sort(int *s, int *t, int n) {
    int aux;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(t[i] > t[j]) {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
                aux = s[i];
                s[i] = s[j];
                s[j] = aux;
            }
        }
    }
}

void spectacol(int *s, int *t, int n) {
    sort(s, t, n);
    int i = 0;
    printf("start %d, final %d\n", s[i], t[i]);
    int j = 0;
    while (i < n-1) {
        if(t[j] <= s[i+1]){
            printf("start %d, final %d\n", s[i+1], t[i+1]);
            j = i+1;
        }
        i++;
    }
}

int main() {

    FILE *in = fopen("spectacol.in","r");
    int n;
    fscanf(in, "%d", &n);
    int s[n+1], t[n+1];
    for(int i = 0; i < n; i++) {
        fscanf(in, "%d", s+i);
        fscanf(in, "%d", t+i);
    }
    spectacol(s, t, n);

    return 0;
}