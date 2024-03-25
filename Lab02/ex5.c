// Sortare prin interclasare

#include<stdio.h>
#include<stdlib.h>

void interclasare(int *v, int i, int m, int j) {
    int n1 = m-i+1;
    int n2 = j-m;
    int v1[n1], v2[n2];
    for(int l = 0; l< n1; l++) {
        v1[l] = v[i+l];
    }
    for(int l = 0; l< n2; l++) {
        v2[l] = v[m+l+1];
    }
    int l = 0, k = 0;
    while (l < n1 && k < n2)
    {
        if (v1[l] <= v2[k]) {
            v[i] = v1[l];
            l++;
        }
        else {
            v[i] = v2[k];
            k++;
        }
        i++;
    }
    while (l < n1) {
        v[i] = v1[l];
        i++;
        l++;
    }
    while (k < n2) {
        v[i] = v2[k];
        i++;
        k++;
    }
}

void sort(int *v, int i, int j) {
    int m = (i+j)/2;
    if(i < j) {
        sort(v,i,m);
        sort(v,m+1,j);
        interclasare(v, i, m, j);
    }
}

int main() {
    FILE *in;
    in = fopen("ex5.txt", "r");
    int n;
    fscanf(in, "%d", &n);
    printf("%d\n", n);
    int *v = (int*)malloc(n * sizeof(int));
    for(int i = 0; i< n; i++) {
        fscanf(in, "%d", v+i);
    }
    for(int i = 0; i< n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    sort(v,0,n-1);

    for(int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    free(v);
    fclose(in);
    return 0;
}
